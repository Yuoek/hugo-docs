---
title: "2810_故障键盘"
date: 2025-10-08T18:39:37+08:00
weight: 2
tags: [二分查找, 前缀和, 动态规划, 单调栈, 哈希表, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 数论, 有序集合, 栈, 模拟, 矩阵, 贪心, 链表]
---

{{< markmap >}}
### [2810_故障键盘](#2810)
#### [字符串](#2810)
#### [模拟](#2810)
### [2811_判断是否能拆分数组](#2811)
#### [贪心](#2811)
#### [数组](#2811)
#### [动态规划](#2811)
### [2812_找出最安全路径](#2812)
#### [广度优先搜索](#2812)
#### [并查集](#2812)
#### [数组](#2812)
#### [二分查找](#2812)
#### [矩阵](#2812)
#### [堆（优先队列）](#2812)
### [2813_子序列最大优雅度](#2813)
#### [栈](#2813)
#### [贪心](#2813)
#### [数组](#2813)
#### [哈希表](#2813)
#### [排序](#2813)
#### [堆（优先队列）](#2813)
### [2814_避免淹死并到达目的地的最短时间 🔒](#2814)
#### [广度优先搜索](#2814)
#### [数组](#2814)
#### [矩阵](#2814)
### [2815_数组中的最大数对和](#2815)
#### [数组](#2815)
#### [哈希表](#2815)
### [2816_翻倍以链表形式表示的数字](#2816)
#### [栈](#2816)
#### [链表](#2816)
#### [数学](#2816)
### [2817_限制条件下元素之间的最小绝对差](#2817)
#### [数组](#2817)
#### [二分查找](#2817)
#### [有序集合](#2817)
### [2818_操作使得分最大](#2818)
#### [栈](#2818)
#### [贪心](#2818)
#### [数组](#2818)
#### [数学](#2818)
#### [数论](#2818)
#### [排序](#2818)
#### [单调栈](#2818)
### [2819_购买巧克力后的最小相对损失 🔒](#2819)
#### [数组](#2819)
#### [二分查找](#2819)
#### [前缀和](#2819)
#### [排序](#2819)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2810_故障键盘
___
#### 字符串
___
#### 模拟
---
### 2811_判断是否能拆分数组
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 2812_找出最安全路径
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
### 2813_子序列最大优雅度
___
#### 栈
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
### 2814_避免淹死并到达目的地的最短时间 🔒
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 2815_数组中的最大数对和
___
#### 数组
___
#### 哈希表
---
### 2816_翻倍以链表形式表示的数字
___
#### 栈
___
#### 链表
___
#### 数学
---
### 2817_限制条件下元素之间的最小绝对差
___
#### 数组
___
#### 二分查找
___
#### 有序集合
---
### 2818_操作使得分最大
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 数论
___
#### 排序
___
#### 单调栈
---
### 2819_购买巧克力后的最小相对损失 🔒
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 单调栈 | 哈希表 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 数论 | 有序集合 | 栈 |
| 模拟 | 矩阵 | 贪心 |
| 链表 |  |  |

# [2810. 故障键盘](https://leetcode.cn/problems/faulty-keyboard){#2810}

{{< tabs "2810" >}}

{{% tab "python" %}}
```python
class Solution:
    def finalString(self, s: str) -> str:
        t = []
        for c in s:
            if c == "i":
                t = t[::-1]
            else:
                t.append(c)
        return "".join(t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String finalString(String s) {
        StringBuilder t = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == 'i') {
                t.reverse();
            } else {
                t.append(c);
            }
        }
        return t.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string finalString(string s) {
        string t;
        for (char c : s) {
            if (c == 'i') {
                reverse(t.begin(), t.end());
            } else {
                t.push_back(c);
            }
        }
        return t;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func finalString(s string) string {
	t := []rune{}
	for _, c := range s {
		if c == 'i' {
			for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
				t[i], t[j] = t[j], t[i]
			}
		} else {
			t = append(t, c)
		}
	}
	return string(t)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function finalString(s: string): string {
    const t: string[] = [];
    for (const c of s) {
        if (c === 'i') {
            t.reverse();
        } else {
            t.push(c);
        }
    }
    return t.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn final_string(s: String) -> String {
        let mut t = Vec::new();
        for c in s.chars() {
            if c == 'i' {
                t.reverse();
            } else {
                t.push(c);
            }
        }
        t.into_iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的笔记本键盘存在故障，每当你在上面输入字符 <code>'i'</code> 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。</p>

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，请你用故障键盘依次输入每个字符。</p>

<p>返回最终笔记本屏幕上输出的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "string"
<strong>输出：</strong>"rtsng"
<strong>解释：</strong>
输入第 1 个字符后，屏幕上的文本是："s" 。
输入第 2 个字符后，屏幕上的文本是："st" 。
输入第 3 个字符后，屏幕上的文本是："str" 。
因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "rts" 。
输入第 5 个字符后，屏幕上的文本是："rtsn" 。
输入第 6 个字符后，屏幕上的文本是： "rtsng" 。
因此，返回 "rtsng" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "poiinter"
<strong>输出：</strong>"ponter"
<strong>解释：</strong>
输入第 1 个字符后，屏幕上的文本是："p" 。
输入第 2 个字符后，屏幕上的文本是："po" 。
因为第 3 个字符是 'i' ，屏幕上的文本被反转，变成 "op" 。
因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "po" 。
输入第 5 个字符后，屏幕上的文本是："pon" 。
输入第 6 个字符后，屏幕上的文本是："pont" 。
输入第 7 个字符后，屏幕上的文本是："ponte" 。
输入第 8 个字符后，屏幕上的文本是："ponter" 。
因此，返回 "ponter" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>s[0] != 'i'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接模拟键盘的输入过程，用一个字符数组 $t$ 来记录屏幕上的文本，初始时 $t$ 为空。

对于字符串 $s$ 中的每个字符 $c$，如果 $c$ 不是字符 $'i'$，那么我们将 $c$ 加入到 $t$ 的末尾；否则我们将 $t$ 中的所有字符反转。

最终答案即为 $t$ 中的字符组成的字符串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def finalString(self, s: str) -> str:
        t = []
        for c in s:
            if c == "i":
                t = t[::-1]
            else:
                t.append(c)
        return "".join(t)
```

#### Java

```java
class Solution {
    public String finalString(String s) {
        StringBuilder t = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == 'i') {
                t.reverse();
            } else {
                t.append(c);
            }
        }
        return t.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string finalString(string s) {
        string t;
        for (char c : s) {
            if (c == 'i') {
                reverse(t.begin(), t.end());
            } else {
                t.push_back(c);
            }
        }
        return t;
    }
};
```

#### Go

```go
func finalString(s string) string {
	t := []rune{}
	for _, c := range s {
		if c == 'i' {
			for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
				t[i], t[j] = t[j], t[i]
			}
		} else {
			t = append(t, c)
		}
	}
	return string(t)
}
```

#### TypeScript

```ts
function finalString(s: string): string {
    const t: string[] = [];
    for (const c of s) {
        if (c === 'i') {
            t.reverse();
        } else {
            t.push(c);
        }
    }
    return t.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn final_string(s: String) -> String {
        let mut t = Vec::new();
        for c in s.chars() {
            if c == 'i' {
                t.reverse();
            } else {
                t.push(c);
            }
        }
        t.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2811. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array){#2811}

{{< tabs "2811" >}}

{{% tab "python" %}}
```python
class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i == j:
                return True
            for k in range(i, j):
                a = k == i or s[k + 1] - s[i] >= m
                b = k == j - 1 or s[j + 1] - s[k + 1] >= m
                if a and b and dfs(i, k) and dfs(k + 1, j):
                    return True
            return False

        s = list(accumulate(nums, initial=0))
        return dfs(0, len(nums) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Boolean[][] f;
    private int[] s;
    private int m;

    public boolean canSplitArray(List<Integer> nums, int m) {
        int n = nums.size();
        f = new Boolean[n][n];
        s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums.get(i - 1);
        }
        this.m = m;
        return dfs(0, n - 1);
    }

    private boolean dfs(int i, int j) {
        if (i == j) {
            return true;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        for (int k = i; k < j; ++k) {
            boolean a = k == i || s[k + 1] - s[i] >= m;
            boolean b = k == j - 1 || s[j + 1] - s[k + 1] >= m;
            if (a && b && dfs(i, k) && dfs(k + 1, j)) {
                return f[i][j] = true;
            }
        }
        return f[i][j] = false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int f[n][n];
        memset(f, -1, sizeof f);
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i == j) {
                return true;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            for (int k = i; k < j; ++k) {
                bool a = k == i || s[k + 1] - s[i] >= m;
                bool b = k == j - 1 || s[j + 1] - s[k + 1] >= m;
                if (a && b && dfs(i, k) && dfs(k + 1, j)) {
                    f[i][j] = 1;
                    return true;
                }
            }
            f[i][j] = 0;
            return false;
        };
        return dfs(0, n - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canSplitArray(nums []int, m int) bool {
	n := len(nums)
	f := make([][]int, n)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i == j {
			return true
		}
		if f[i][j] != 0 {
			return f[i][j] == 1
		}
		for k := i; k < j; k++ {
			a := k == i || s[k+1]-s[i] >= m
			b := k == j-1 || s[j+1]-s[k+1] >= m
			if a && b && dfs(i, k) && dfs(k+1, j) {
				f[i][j] = 1
				return true
			}
		}
		f[i][j] = -1
		return false
	}
	return dfs(0, n-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canSplitArray(nums: number[], m: number): boolean {
    const n = nums.length;
    if (n <= 2) {
        return true;
    }
    for (let i = 1; i < n; i++) {
        if (nums[i - 1] + nums[i] >= m) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_split_array(nums: Vec<i32>, m: i32) -> bool {
        let n = nums.len();
        if n <= 2 {
            return true;
        }
        for i in 1..n {
            if nums[i - 1] + nums[i] >= m {
                return true;
            }
        }
        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的数组 <code>nums</code> 和一个整数 <code>m</code> 。请你判断能否执行一系列操作，将数组拆分成 <code>n</code> 个 <strong>非空 </strong>数组。</p>

<p>一个数组被称为 <strong>好</strong> 的，如果：</p>

<ul>
	<li>子数组的长度为 1 ，或者</li>
	<li>子数组元素之和 <strong>大于或等于</strong>&nbsp; <code>m</code> 。</li>
</ul>

<p>在每一步操作中，你可以选择一个 <strong>长度至少为 2</strong> 的现有数组（之前步骤的结果） 并将其拆分成 <strong>2</strong> 个子数组，而得到的 <strong>每个</strong> 子数组都需要是好的。</p>

<p>如果你可以将给定数组拆分成 <code>n</code> 个满足要求的数组，返回 <code>true</code><em> </em>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2, 2, 1], m = 4</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>将 <code>[2, 2, 1]</code> <span class="example-io">切分为</span> <code>[2, 2]</code> 和&nbsp;<code>[1]</code>。数组 <code>[1]</code> 的长度为 1，数组 <code>[2, 2]</code> 的元素之和等于 <code>4 &gt;= m</code>，所以两者都是好的数组。</li>
	<li>将 <code>[2, 2]</code> <span class="example-io">切分为</span> <code>[2]</code> 和&nbsp;<code>[2]</code>。两个数组的长度都是 1，所以都是好的数组。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [2, 1, 3], m = 5</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>第一步必须是以下之一：</p>

<ul>
	<li>将&nbsp;<code>[2, 1, 3]</code> <span class="example-io">切分为</span> <code>[2, 1]</code> 和&nbsp;<code>[3]</code>。数组&nbsp;<code>[2, 1]</code> 既不是长度为 1，也没有大于或等于 <code>m</code> 的元素和。</li>
	<li>将 <code>[2, 1, 3]</code> <span class="example-io">切分为</span> <code>[2]</code> 和 <code>[1, 3]</code>。数组&nbsp;<code>[1, 3]</code> 既不是长度为 1，也没有大于或等于 <code>m</code> 的元素和。</li>
</ul>

<p>因此，由于这两个操作都无效（它们没有将数组分成两个好的数组），因此我们无法将 <code>nums</code> 分成 <code>n</code> 个大小为 1 的数组。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [2, 3, 3, 2, 3], m = 6</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><span class="example-io">将&nbsp;<code>[2, 3, 3, 2, 3]</code>&nbsp;切分为&nbsp;<code>[2]</code> 和&nbsp;<code>[3, 3, 2, 3]</code>。</span></li>
	<li><span class="example-io">将 <code>[3, 3, 2, 3]</code> 切分为 <code>[3, 3, 2]</code> 和 <code>[3]</code>。</span></li>
	<li><span class="example-io">将 <code>[3, 3, 2]</code> 切分为 <code>[3, 3]</code> 和 <code>[2]</code>。</span></li>
	<li><span class="example-io">将 <code>[3, 3]</code> 切分为 <code>[3]</code> 和 <code>[3]</code>。</span></li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= m &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们先预处理得到前缀和数组 $s$，其中 $s[i]$ 表示数组 $nums$ 的前 $i$ 个元素之和。

接下来，我们设计一个函数 $dfs(i, j)$，表示对于数组 $nums$ 的下标范围 $[i, j]$，是否存在一种满足条件的拆分方法。如果存在，返回 `true`，否则返回 `false`。

函数 $dfs(i, j)$ 的计算过程如下：

如果 $i = j$，那么只有一个元素，不需要拆分，返回 `true`；

否则，我们枚举拆分点 $k$，其中 $k \in [i, j]$，如果满足以下条件，那么就可以拆分成 $nums[i,.. k]$ 和 $nums[k + 1,.. j]$ 两个子数组：

-   子数组 $nums[i,..k]$ 只有一个元素，或者子数组 $nums[i,..k]$ 的元素之和大于等于 $m$；
-   子数组 $nums[k + 1,..j]$ 只有一个元素，或者子数组 $nums[k + 1,..j]$ 的元素之和大于等于 $m$；
-   $dfs(i, k)$ 和 $dfs(k + 1, j)$ 都为 `true`。

为了避免重复计算，我们使用记忆化搜索的方法，用一个二维数组 $f$ 记录所有的 $dfs(i, j)$ 的返回值，其中 $f[i][j]$ 表示 $dfs(i, j)$ 的返回值。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i == j:
                return True
            for k in range(i, j):
                a = k == i or s[k + 1] - s[i] >= m
                b = k == j - 1 or s[j + 1] - s[k + 1] >= m
                if a and b and dfs(i, k) and dfs(k + 1, j):
                    return True
            return False

        s = list(accumulate(nums, initial=0))
        return dfs(0, len(nums) - 1)
```

#### Java

```java
class Solution {
    private Boolean[][] f;
    private int[] s;
    private int m;

    public boolean canSplitArray(List<Integer> nums, int m) {
        int n = nums.size();
        f = new Boolean[n][n];
        s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums.get(i - 1);
        }
        this.m = m;
        return dfs(0, n - 1);
    }

    private boolean dfs(int i, int j) {
        if (i == j) {
            return true;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        for (int k = i; k < j; ++k) {
            boolean a = k == i || s[k + 1] - s[i] >= m;
            boolean b = k == j - 1 || s[j + 1] - s[k + 1] >= m;
            if (a && b && dfs(i, k) && dfs(k + 1, j)) {
                return f[i][j] = true;
            }
        }
        return f[i][j] = false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int f[n][n];
        memset(f, -1, sizeof f);
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i == j) {
                return true;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            for (int k = i; k < j; ++k) {
                bool a = k == i || s[k + 1] - s[i] >= m;
                bool b = k == j - 1 || s[j + 1] - s[k + 1] >= m;
                if (a && b && dfs(i, k) && dfs(k + 1, j)) {
                    f[i][j] = 1;
                    return true;
                }
            }
            f[i][j] = 0;
            return false;
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func canSplitArray(nums []int, m int) bool {
	n := len(nums)
	f := make([][]int, n)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i == j {
			return true
		}
		if f[i][j] != 0 {
			return f[i][j] == 1
		}
		for k := i; k < j; k++ {
			a := k == i || s[k+1]-s[i] >= m
			b := k == j-1 || s[j+1]-s[k+1] >= m
			if a && b && dfs(i, k) && dfs(k+1, j) {
				f[i][j] = 1
				return true
			}
		}
		f[i][j] = -1
		return false
	}
	return dfs(0, n-1)
}
```

#### TypeScript

```ts
function canSplitArray(nums: number[], m: number): boolean {
    const n = nums.length;
    const s: number[] = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + nums[i - 1];
    }
    const f: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(-1));
    const dfs = (i: number, j: number): boolean => {
        if (i === j) {
            return true;
        }
        if (f[i][j] !== -1) {
            return f[i][j] === 1;
        }
        for (let k = i; k < j; ++k) {
            const a = k === i || s[k + 1] - s[i] >= m;
            const b = k === j - 1 || s[j + 1] - s[k + 1] >= m;
            if (a && b && dfs(i, k) && dfs(k + 1, j)) {
                f[i][j] = 1;
                return true;
            }
        }
        f[i][j] = 0;
        return false;
    };
    return dfs(0, n - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn can_split_array(nums: Vec<i32>, m: i32) -> bool {
        let n = nums.len();
        if n <= 2 {
            return true;
        }
        for i in 1..n {
            if nums[i - 1] + nums[i] >= m {
                return true;
            }
        }
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：脑筋急转弯

不论如何操作，最终总会剩下一个 `length == 2` 的子数组，又因为元素数值不存在负数，所以随着分割操作的进行，子数组的长度和总和都会逐渐变小，其它 `length > 2` 子数组之和肯定要比该子数组之和更大，进而，我们只需要考虑，是否存在一个 `length == 2` 且总和大于等于 `m` 的子数组即可。

> 📢 注意，当 `nums.length <= 2` 时，无需进行操作。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### TypeScript

```ts
function canSplitArray(nums: number[], m: number): boolean {
    const n = nums.length;
    if (n <= 2) {
        return true;
    }
    for (let i = 1; i < n; i++) {
        if (nums[i - 1] + nums[i] >= m) {
            return true;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid){#2812}

{{< tabs "2812" >}}

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
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] or grid[n - 1][n - 1]:
            return 0
        q = deque()
        dist = [[inf] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    q.append((i, j))
                    dist[i][j] = 0
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and dist[x][y] == inf:
                    dist[x][y] = dist[i][j] + 1
                    q.append((x, y))

        q = ((dist[i][j], i, j) for i in range(n) for j in range(n))
        q = sorted(q, reverse=True)
        uf = UnionFind(n * n)
        for d, i, j in q:
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and dist[x][y] >= d:
                    uf.union(i * n + j, x * n + y)
            if uf.find(0) == uf.find(n * n - 1):
                return int(d)
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        if (grid.get(0).get(0) == 1 || grid.get(n - 1).get(n - 1) == 1) {
            return 0;
        }
        Deque<int[]> q = new ArrayDeque<>();
        int[][] dist = new int[n][n];
        final int inf = 1 << 30;
        for (int[] d : dist) {
            Arrays.fill(d, inf);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid.get(i).get(j) == 1) {
                    dist[i][j] = 0;
                    q.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == inf) {
                    dist[x][y] = dist[i][j] + 1;
                    q.offer(new int[] {x, y});
                }
            }
        }
        List<int[]> t = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t.add(new int[] {dist[i][j], i, j});
            }
        }
        t.sort((a, b) -> Integer.compare(b[0], a[0]));
        UnionFind uf = new UnionFind(n * n);
        for (int[] p : t) {
            int d = p[0], i = p[1], j = p[2];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d) {
                    uf.union(i * n + j, x * n + y);
                }
            }
            if (uf.find(0) == uf.find(n * n - 1)) {
                return d;
            }
        }
        return 0;
    }
}

class UnionFind {
    public int[] p;
    public int n;

    public UnionFind(int n) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        this.n = n;
    }

    public boolean union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return false;
        }
        p[pa] = pb;
        --n;
        return true;
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    vector<int> p;
    int n;

    UnionFind(int _n)
        : n(_n)
        , p(_n) {
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        p[pa] = pb;
        --n;
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        queue<pair<int, int>> q;
        int dist[n][n];
        memset(dist, 0x3f, sizeof(dist));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == 0x3f3f3f3f) {
                    dist[x][y] = dist[i][j] + 1;
                    q.emplace(x, y);
                }
            }
        }
        vector<tuple<int, int, int>> t;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t.emplace_back(dist[i][j], i, j);
            }
        }
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        UnionFind uf(n * n);
        for (auto [d, i, j] : t) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d) {
                    uf.unite(i * n + j, x * n + y);
                }
            }
            if (uf.find(0) == uf.find(n * n - 1)) {
                return d;
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p []int
	n int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	return &unionFind{p, n}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	if uf.find(a) == uf.find(b) {
		return false
	}
	uf.p[uf.find(a)] = uf.find(b)
	uf.n--
	return true
}

func maximumSafenessFactor(grid [][]int) int {
	n := len(grid)
	if grid[0][0] == 1 || grid[n-1][n-1] == 1 {
		return 0
	}
	q := [][2]int{}
	dist := make([][]int, n)
	const inf = 1 << 30
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = inf
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				dist[i][j] = 0
				q = append(q, [2]int{i, j})
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == inf {
				dist[x][y] = dist[i][j] + 1
				q = append(q, [2]int{x, y})
			}
		}
	}
	t := [][3]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			t = append(t, [3]int{dist[i][j], i, j})
		}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] > t[j][0]
	})
	uf := newUnionFind(n * n)
	for _, p := range t {
		d, i, j := p[0], p[1], p[2]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d {
				uf.union(i*n+j, x*n+y)
			}
		}
		if uf.find(0) == uf.find(n*n-1) {
			return d
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSafenessFactor(grid: number[][]): number {
    const n = grid.length;
    const g = Array.from({ length: n }, () => new Array(n).fill(-1));
    const vis = Array.from({ length: n }, () => new Array(n).fill(false));
    let q: [number, number][] = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
            }
        }
    }
    let level = 0;
    while (q.length) {
        const t: [number, number][] = [];
        for (const [x, y] of q) {
            if (x < 0 || y < 0 || x === n || y === n || g[x][y] !== -1) {
                continue;
            }
            g[x][y] = level;
            t.push([x + 1, y]);
            t.push([x - 1, y]);
            t.push([x, y + 1]);
            t.push([x, y - 1]);
        }
        q = t;
        level++;
    }
    const dfs = (i: number, j: number, v: number) => {
        if (i < 0 || j < 0 || i === n || j === n || vis[i][j] || g[i][j] <= v) {
            return false;
        }
        vis[i][j] = true;
        return (
            (i === n - 1 && j === n - 1) ||
            dfs(i + 1, j, v) ||
            dfs(i, j + 1, v) ||
            dfs(i - 1, j, v) ||
            dfs(i, j - 1, v)
        );
    };

    let left = 0;
    let right = level;
    while (left < right) {
        vis.forEach(v => v.fill(false));
        const mid = (left + right) >>> 1;
        if (dfs(0, 0, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;
impl Solution {
    fn dfs(i: usize, j: usize, v: i32, g: &Vec<Vec<i32>>, vis: &mut Vec<Vec<bool>>) -> bool {
        if vis[i][j] || g[i][j] <= v {
            return false;
        }
        vis[i][j] = true;
        let n = g.len();
        (i == n - 1 && j == n - 1)
            || (i != 0 && Self::dfs(i - 1, j, v, g, vis))
            || (i != n - 1 && Self::dfs(i + 1, j, v, g, vis))
            || (j != 0 && Self::dfs(i, j - 1, v, g, vis))
            || (j != n - 1 && Self::dfs(i, j + 1, v, g, vis))
    }

    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut g = vec![vec![-1; n]; n];
        let mut q = VecDeque::new();
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    q.push_back((i, j));
                }
            }
        }
        let mut level = 0;
        while !q.is_empty() {
            let m = q.len();
            for _ in 0..m {
                let (i, j) = q.pop_front().unwrap();
                if g[i][j] != -1 {
                    continue;
                }
                g[i][j] = level;
                if i != n - 1 {
                    q.push_back((i + 1, j));
                }
                if i != 0 {
                    q.push_back((i - 1, j));
                }
                if j != n - 1 {
                    q.push_back((i, j + 1));
                }
                if j != 0 {
                    q.push_back((i, j - 1));
                }
            }
            level += 1;
        }
        let mut left = 0;
        let mut right = level;
        while left < right {
            let mid = (left + right) >> 1;
            if Self::dfs(0, 0, mid, &g, &mut vec![vec![false; n]; n]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        right
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n x n</code> 的二维矩阵 <code>grid</code> ，其中 <code>(r, c)</code> 表示：</p>

<ul>
	<li>如果 <code>grid[r][c] = 1</code> ，则表示一个存在小偷的单元格</li>
	<li>如果 <code>grid[r][c] = 0</code> ，则表示一个空单元格</li>
</ul>

<p>你最开始位于单元格 <code>(0, 0)</code> 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。</p>

<p>矩阵中路径的 <strong>安全系数</strong> 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 <strong>最小</strong> 曼哈顿距离。</p>

<p>返回所有通向单元格<em> </em><code>(n - 1, n - 1)</code> 的路径中的 <strong>最大安全系数</strong> 。</p>

<p>单元格 <code>(r, c)</code> 的某个 <strong>相邻</strong> 单元格，是指在矩阵中存在的 <code>(r, c + 1)</code>、<code>(r, c - 1)</code>、<code>(r + 1, c)</code> 和 <code>(r - 1, c)</code> 之一。</p>

<p>两个单元格 <code>(a, b)</code> 和 <code>(x, y)</code> 之间的 <strong>曼哈顿距离</strong> 等于 <code>| a - x | + | b - y |</code> ，其中 <code>|val|</code> 表示 <code>val</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2812.Find%20the%20Safest%20Path%20in%20a%20Grid/images/example1.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[1,0,0],[0,0,0],[0,0,1]]
<strong>输出：</strong>0
<strong>解释：</strong>从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2812.Find%20the%20Safest%20Path%20in%20a%20Grid/images/example2.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,1],[0,0,0],[0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2812.Find%20the%20Safest%20Path%20in%20a%20Grid/images/example3.png" style="width: 362px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
- 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length == n &lt;= 400</code></li>
	<li><code>grid[i].length == n</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>grid</code> 至少存在一个小偷</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多源 BFS + 排序 + 并查集

我们可以先找出所有小偷的位置，然后从这些位置开始进行多源 BFS，得到每个位置到小偷的最短距离，然后按照距离从大到小排序，将每个位置逐个加入并查集，如果最终起点和终点在同一个连通分量中，那么当前距离就是答案。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n^2)$。

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


class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] or grid[n - 1][n - 1]:
            return 0
        q = deque()
        dist = [[inf] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    q.append((i, j))
                    dist[i][j] = 0
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and dist[x][y] == inf:
                    dist[x][y] = dist[i][j] + 1
                    q.append((x, y))

        q = ((dist[i][j], i, j) for i in range(n) for j in range(n))
        q = sorted(q, reverse=True)
        uf = UnionFind(n * n)
        for d, i, j in q:
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and dist[x][y] >= d:
                    uf.union(i * n + j, x * n + y)
            if uf.find(0) == uf.find(n * n - 1):
                return int(d)
        return 0
```

#### Java

```java
class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        if (grid.get(0).get(0) == 1 || grid.get(n - 1).get(n - 1) == 1) {
            return 0;
        }
        Deque<int[]> q = new ArrayDeque<>();
        int[][] dist = new int[n][n];
        final int inf = 1 << 30;
        for (int[] d : dist) {
            Arrays.fill(d, inf);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid.get(i).get(j) == 1) {
                    dist[i][j] = 0;
                    q.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == inf) {
                    dist[x][y] = dist[i][j] + 1;
                    q.offer(new int[] {x, y});
                }
            }
        }
        List<int[]> t = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t.add(new int[] {dist[i][j], i, j});
            }
        }
        t.sort((a, b) -> Integer.compare(b[0], a[0]));
        UnionFind uf = new UnionFind(n * n);
        for (int[] p : t) {
            int d = p[0], i = p[1], j = p[2];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d) {
                    uf.union(i * n + j, x * n + y);
                }
            }
            if (uf.find(0) == uf.find(n * n - 1)) {
                return d;
            }
        }
        return 0;
    }
}

class UnionFind {
    public int[] p;
    public int n;

    public UnionFind(int n) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        this.n = n;
    }

    public boolean union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return false;
        }
        p[pa] = pb;
        --n;
        return true;
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    vector<int> p;
    int n;

    UnionFind(int _n)
        : n(_n)
        , p(_n) {
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        p[pa] = pb;
        --n;
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        queue<pair<int, int>> q;
        int dist[n][n];
        memset(dist, 0x3f, sizeof(dist));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == 0x3f3f3f3f) {
                    dist[x][y] = dist[i][j] + 1;
                    q.emplace(x, y);
                }
            }
        }
        vector<tuple<int, int, int>> t;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t.emplace_back(dist[i][j], i, j);
            }
        }
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        UnionFind uf(n * n);
        for (auto [d, i, j] : t) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d) {
                    uf.unite(i * n + j, x * n + y);
                }
            }
            if (uf.find(0) == uf.find(n * n - 1)) {
                return d;
            }
        }
        return 0;
    }
};
```

#### Go

```go
type unionFind struct {
	p []int
	n int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	return &unionFind{p, n}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	if uf.find(a) == uf.find(b) {
		return false
	}
	uf.p[uf.find(a)] = uf.find(b)
	uf.n--
	return true
}

func maximumSafenessFactor(grid [][]int) int {
	n := len(grid)
	if grid[0][0] == 1 || grid[n-1][n-1] == 1 {
		return 0
	}
	q := [][2]int{}
	dist := make([][]int, n)
	const inf = 1 << 30
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = inf
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				dist[i][j] = 0
				q = append(q, [2]int{i, j})
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == inf {
				dist[x][y] = dist[i][j] + 1
				q = append(q, [2]int{x, y})
			}
		}
	}
	t := [][3]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			t = append(t, [3]int{dist[i][j], i, j})
		}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] > t[j][0]
	})
	uf := newUnionFind(n * n)
	for _, p := range t {
		d, i, j := p[0], p[1], p[2]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d {
				uf.union(i*n+j, x*n+y)
			}
		}
		if uf.find(0) == uf.find(n*n-1) {
			return d
		}
	}
	return 0
}
```

#### TypeScript

```ts
class UnionFind {
    private p: number[];
    private n: number;

    constructor(n: number) {
        this.n = n;
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
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
        if (pa !== pb) {
            this.p[pa] = pb;
            this.n--;
            return true;
        }
        return false;
    }
}

function maximumSafenessFactor(grid: number[][]): number {
    const n = grid.length;
    if (grid[0][0] === 1 || grid[n - 1][n - 1] === 1) {
        return 0;
    }
    const q: number[][] = [];
    const inf = 1 << 30;
    const dist: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(inf));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                dist[i][j] = 0;
                q.push([i, j]);
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length) {
        const [i, j] = q.shift()!;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] === inf) {
                dist[x][y] = dist[i][j] + 1;
                q.push([x, y]);
            }
        }
    }
    const t: number[][] = [];
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            t.push([dist[i][j], i, j]);
        }
    }
    t.sort((a, b) => b[0] - a[0]);
    const uf = new UnionFind(n * n);
    for (const [d, i, j] of t) {
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= d) {
                uf.union(i * n + j, x * n + y);
            }
        }
        if (uf.find(0) == uf.find(n * n - 1)) {
            return d;
        }
    }
    return 0;
}
```

#### Rust

```rust
use std::collections::VecDeque;
impl Solution {
    fn dfs(i: usize, j: usize, v: i32, g: &Vec<Vec<i32>>, vis: &mut Vec<Vec<bool>>) -> bool {
        if vis[i][j] || g[i][j] <= v {
            return false;
        }
        vis[i][j] = true;
        let n = g.len();
        (i == n - 1 && j == n - 1)
            || (i != 0 && Self::dfs(i - 1, j, v, g, vis))
            || (i != n - 1 && Self::dfs(i + 1, j, v, g, vis))
            || (j != 0 && Self::dfs(i, j - 1, v, g, vis))
            || (j != n - 1 && Self::dfs(i, j + 1, v, g, vis))
    }

    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut g = vec![vec![-1; n]; n];
        let mut q = VecDeque::new();
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    q.push_back((i, j));
                }
            }
        }
        let mut level = 0;
        while !q.is_empty() {
            let m = q.len();
            for _ in 0..m {
                let (i, j) = q.pop_front().unwrap();
                if g[i][j] != -1 {
                    continue;
                }
                g[i][j] = level;
                if i != n - 1 {
                    q.push_back((i + 1, j));
                }
                if i != 0 {
                    q.push_back((i - 1, j));
                }
                if j != n - 1 {
                    q.push_back((i, j + 1));
                }
                if j != 0 {
                    q.push_back((i, j - 1));
                }
            }
            level += 1;
        }
        let mut left = 0;
        let mut right = level;
        while left < right {
            let mid = (left + right) >> 1;
            if Self::dfs(0, 0, mid, &g, &mut vec![vec![false; n]; n]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        right
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function maximumSafenessFactor(grid: number[][]): number {
    const n = grid.length;
    const g = Array.from({ length: n }, () => new Array(n).fill(-1));
    const vis = Array.from({ length: n }, () => new Array(n).fill(false));
    let q: [number, number][] = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
            }
        }
    }
    let level = 0;
    while (q.length) {
        const t: [number, number][] = [];
        for (const [x, y] of q) {
            if (x < 0 || y < 0 || x === n || y === n || g[x][y] !== -1) {
                continue;
            }
            g[x][y] = level;
            t.push([x + 1, y]);
            t.push([x - 1, y]);
            t.push([x, y + 1]);
            t.push([x, y - 1]);
        }
        q = t;
        level++;
    }
    const dfs = (i: number, j: number, v: number) => {
        if (i < 0 || j < 0 || i === n || j === n || vis[i][j] || g[i][j] <= v) {
            return false;
        }
        vis[i][j] = true;
        return (
            (i === n - 1 && j === n - 1) ||
            dfs(i + 1, j, v) ||
            dfs(i, j + 1, v) ||
            dfs(i - 1, j, v) ||
            dfs(i, j - 1, v)
        );
    };

    let left = 0;
    let right = level;
    while (left < right) {
        vis.forEach(v => v.fill(false));
        const mid = (left + right) >>> 1;
        if (dfs(0, 0, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2813. 子序列最大优雅度](https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence){#2813}

{{< tabs "2813" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(key=lambda x: -x[0])
        tot = 0
        vis = set()
        dup = []
        for p, c in items[:k]:
            tot += p
            if c not in vis:
                vis.add(c)
            else:
                dup.append(p)
        ans = tot + len(vis) ** 2
        for p, c in items[k:]:
            if c in vis or not dup:
                continue
            vis.add(c)
            tot += p - dup.pop()
            ans = max(ans, tot + len(vis) ** 2)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long findMaximumElegance(int[][] items, int k) {
        Arrays.sort(items, (a, b) -> b[0] - a[0]);
        int n = items.length;
        long tot = 0;
        Set<Integer> vis = new HashSet<>();
        Deque<Integer> dup = new ArrayDeque<>();
        for (int i = 0; i < k; ++i) {
            int p = items[i][0], c = items[i][1];
            tot += p;
            if (!vis.add(c)) {
                dup.push(p);
            }
        }
        long ans = tot + (long) vis.size() * vis.size();
        for (int i = k; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (vis.contains(c) || dup.isEmpty()) {
                continue;
            }
            vis.add(c);
            tot += p - dup.pop();
            ans = Math.max(ans, tot + (long) vis.size() * vis.size());
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
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        long long tot = 0;
        unordered_set<int> vis;
        stack<int> dup;
        for (int i = 0; i < k; ++i) {
            int p = items[i][0], c = items[i][1];
            tot += p;
            if (vis.count(c)) {
                dup.push(p);
            } else {
                vis.insert(c);
            }
        }
        int n = items.size();
        long long ans = tot + 1LL * vis.size() * vis.size();
        for (int i = k; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (vis.count(c) || dup.empty()) {
                continue;
            }
            vis.insert(c);
            tot += p - dup.top();
            dup.pop();
            ans = max(ans, tot + (long long) (1LL * vis.size() * vis.size()));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximumElegance(items [][]int, k int) int64 {
	sort.Slice(items, func(i, j int) bool { return items[i][0] > items[j][0] })
	tot := 0
	vis := map[int]bool{}
	dup := []int{}
	for _, item := range items[:k] {
		p, c := item[0], item[1]
		tot += p
		if vis[c] {
			dup = append(dup, p)
		} else {
			vis[c] = true
		}
	}
	ans := tot + len(vis)*len(vis)
	for _, item := range items[k:] {
		p, c := item[0], item[1]
		if vis[c] || len(dup) == 0 {
			continue
		}
		vis[c] = true
		tot += p - dup[len(dup)-1]
		dup = dup[:len(dup)-1]
		ans = max(ans, tot+len(vis)*len(vis))
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaximumElegance(items: number[][], k: number): number {
    items.sort((a, b) => b[0] - a[0]);
    let tot = 0;
    const vis: Set<number> = new Set();
    const dup: number[] = [];
    for (const [p, c] of items.slice(0, k)) {
        tot += p;
        if (vis.has(c)) {
            dup.push(p);
        } else {
            vis.add(c);
        }
    }
    let ans = tot + vis.size ** 2;
    for (const [p, c] of items.slice(k)) {
        if (vis.has(c) || dup.length === 0) {
            continue;
        }
        tot += p - dup.pop()!;
        vis.add(c);
        ans = Math.max(ans, tot + vis.size ** 2);
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

<p>给你一个长度为 <code>n</code> 的二维整数数组 <code>items</code> 和一个整数 <code>k</code> 。</p>

<p><code>items[i] = [profit<sub>i</sub>, category<sub>i</sub>]</code>，其中 <code>profit<sub>i</sub></code> 和 <code>category<sub>i</sub></code> 分别表示第 <code>i</code> 个项目的利润和类别。</p>

<p>现定义&nbsp;<code>items</code> 的 <strong>子序列</strong> 的 <strong>优雅度</strong> 可以用 <code>total_profit + distinct_categories<sup>2</sup></code> 计算，其中 <code>total_profit</code> 是子序列中所有项目的利润总和，<code>distinct_categories</code> 是所选子序列所含的所有类别中不同类别的数量。</p>

<p>你的任务是从 <code>items</code> 所有长度为 <code>k</code> 的子序列中，找出 <strong>最大优雅度</strong> 。</p>

<p>用整数形式表示并返回 <code>items</code> 中所有长度恰好为 <code>k</code> 的子序列的最大优雅度。</p>

<p><strong>注意：</strong>数组的子序列是经由原数组删除一些元素（可能不删除）而产生的新数组，且删除不改变其余元素相对顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>items = [[3,2],[5,1],[10,1]], k = 2
<strong>输出：</strong>17
<strong>解释：
</strong>在这个例子中，我们需要选出长度为 2 的子序列。
其中一种方案是 items[0] = [3,2] 和 items[2] = [10,1] 。
子序列的总利润为 3 + 10 = 13 ，子序列包含 2 种不同类别 [2,1] 。
因此，优雅度为 13 + 2<sup>2</sup> = 17 ，可以证明 17 是可以获得的最大优雅度。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>items = [[3,1],[3,1],[2,2],[5,3]], k = 3
<strong>输出：</strong>19
<strong>解释：</strong>
在这个例子中，我们需要选出长度为 3 的子序列。 
其中一种方案是 items[0] = [3,1] ，items[2] = [2,2] 和 items[3] = [5,3] 。
子序列的总利润为 3 + 2 + 5 = 10 ，子序列包含 3 种不同类别 [1, 2, 3] 。 
因此，优雅度为 10 + 3<sup>2</sup> = 19 ，可以证明 19 是可以获得的最大优雅度。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>items = [[1,1],[2,1],[3,1]], k = 3
<strong>输出：</strong>7
<strong>解释：
</strong>在这个例子中，我们需要选出长度为 3 的子序列。
我们需要选中所有项目。
子序列的总利润为 1 + 2 + 3 = 6，子序列包含 1 种不同类别 [1] 。
因此，最大优雅度为 6 + 1<sup>2</sup> = 7 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>items[i][0] == profit<sub>i</sub></code></li>
	<li><code>items[i][1] == category<sub>i</sub></code></li>
	<li><code>1 &lt;= profit<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= category<sub>i</sub> &lt;= n </code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以将所有项目按照利润从大到小排序，先选取前 $k$ 个项目，计算其总利润 $tot$，用一个哈希表 $vis$ 记录这 $k$ 个项目的类别，用一个栈 $dup$ 按顺序记录这 $k$ 个项目中重复类别的利润，用一个变量 $ans$ 记录当前的最大优雅度。

接下来，我们考虑从第 $k+1$ 个项目开始，如果其类别已经在 $vis$ 中，这意味着如果选择该类别，不会使得不同的类别数量增加，因此我们可以直接跳过该项目。如果此前不存在重复类别，我们也可以直接跳过该项目。否则，我们可以考虑将 $dup$ 栈顶的项目（即重复类别中利润最小的项目）替换为当前项目，这样可以使得总利润增加 $p - dup.pop()$，同时不同类别数量增加 $1$，因此我们可以更新 $tot$ 和 $ans$。

最后，我们返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为项目数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(key=lambda x: -x[0])
        tot = 0
        vis = set()
        dup = []
        for p, c in items[:k]:
            tot += p
            if c not in vis:
                vis.add(c)
            else:
                dup.append(p)
        ans = tot + len(vis) ** 2
        for p, c in items[k:]:
            if c in vis or not dup:
                continue
            vis.add(c)
            tot += p - dup.pop()
            ans = max(ans, tot + len(vis) ** 2)
        return ans
```

#### Java

```java
class Solution {
    public long findMaximumElegance(int[][] items, int k) {
        Arrays.sort(items, (a, b) -> b[0] - a[0]);
        int n = items.length;
        long tot = 0;
        Set<Integer> vis = new HashSet<>();
        Deque<Integer> dup = new ArrayDeque<>();
        for (int i = 0; i < k; ++i) {
            int p = items[i][0], c = items[i][1];
            tot += p;
            if (!vis.add(c)) {
                dup.push(p);
            }
        }
        long ans = tot + (long) vis.size() * vis.size();
        for (int i = k; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (vis.contains(c) || dup.isEmpty()) {
                continue;
            }
            vis.add(c);
            tot += p - dup.pop();
            ans = Math.max(ans, tot + (long) vis.size() * vis.size());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        long long tot = 0;
        unordered_set<int> vis;
        stack<int> dup;
        for (int i = 0; i < k; ++i) {
            int p = items[i][0], c = items[i][1];
            tot += p;
            if (vis.count(c)) {
                dup.push(p);
            } else {
                vis.insert(c);
            }
        }
        int n = items.size();
        long long ans = tot + 1LL * vis.size() * vis.size();
        for (int i = k; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (vis.count(c) || dup.empty()) {
                continue;
            }
            vis.insert(c);
            tot += p - dup.top();
            dup.pop();
            ans = max(ans, tot + (long long) (1LL * vis.size() * vis.size()));
        }
        return ans;
    }
};
```

#### Go

```go
func findMaximumElegance(items [][]int, k int) int64 {
	sort.Slice(items, func(i, j int) bool { return items[i][0] > items[j][0] })
	tot := 0
	vis := map[int]bool{}
	dup := []int{}
	for _, item := range items[:k] {
		p, c := item[0], item[1]
		tot += p
		if vis[c] {
			dup = append(dup, p)
		} else {
			vis[c] = true
		}
	}
	ans := tot + len(vis)*len(vis)
	for _, item := range items[k:] {
		p, c := item[0], item[1]
		if vis[c] || len(dup) == 0 {
			continue
		}
		vis[c] = true
		tot += p - dup[len(dup)-1]
		dup = dup[:len(dup)-1]
		ans = max(ans, tot+len(vis)*len(vis))
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function findMaximumElegance(items: number[][], k: number): number {
    items.sort((a, b) => b[0] - a[0]);
    let tot = 0;
    const vis: Set<number> = new Set();
    const dup: number[] = [];
    for (const [p, c] of items.slice(0, k)) {
        tot += p;
        if (vis.has(c)) {
            dup.push(p);
        } else {
            vis.add(c);
        }
    }
    let ans = tot + vis.size ** 2;
    for (const [p, c] of items.slice(k)) {
        if (vis.has(c) || dup.length === 0) {
            continue;
        }
        tot += p - dup.pop()!;
        vis.add(c);
        ans = Math.max(ans, tot + vis.size ** 2);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2814. 避免淹死并到达目的地的最短时间 🔒](https://leetcode.cn/problems/minimum-time-takes-to-reach-destination-without-drowning){#2814}

{{< tabs "2814" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSeconds(self, land: List[List[str]]) -> int:
        m, n = len(land), len(land[0])
        vis = [[False] * n for _ in range(m)]
        g = [[inf] * n for _ in range(m)]
        q = deque()
        si = sj = 0
        for i, row in enumerate(land):
            for j, c in enumerate(row):
                match c:
                    case "*":
                        q.append((i, j))
                    case "S":
                        si, sj = i, j
        dirs = (-1, 0, 1, 0, -1)
        t = 0
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                g[i][j] = t
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (
                        0 <= x < m
                        and 0 <= y < n
                        and not vis[x][y]
                        and land[x][y] in ".S"
                    ):
                        vis[x][y] = True
                        q.append((x, y))
            t += 1
        t = 0
        q = deque([(si, sj)])
        vis = [[False] * n for _ in range(m)]
        vis[si][sj] = True
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if land[i][j] == "D":
                    return t
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (
                        0 <= x < m
                        and 0 <= y < n
                        and g[x][y] > t + 1
                        and not vis[x][y]
                        and land[x][y] in ".D"
                    ):
                        vis[x][y] = True
                        q.append((x, y))
            t += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSeconds(List<List<String>> land) {
        int m = land.size(), n = land.get(0).size();
        boolean[][] vis = new boolean[m][n];
        int[][] g = new int[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            Arrays.fill(g[i], 1 << 30);
            for (int j = 0; j < n; ++j) {
                String c = land.get(i).get(j);
                if ("*".equals(c)) {
                    q.offer(new int[] {i, j});
                } else if ("S".equals(c)) {
                    si = i;
                    sj = j;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; !q.isEmpty(); ++t) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                int i = p[0], j = p[1];
                g[i][j] = t;
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        boolean empty = ".".equals(land.get(x).get(y));
                        boolean start = "S".equals(land.get(x).get(y));
                        if (empty || start) {
                            vis[x][y] = true;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        q.offer(new int[] {si, sj});
        vis = new boolean[m][n];
        vis[si][sj] = true;
        for (int t = 0; !q.isEmpty(); ++t) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                int i = p[0], j = p[1];
                if ("D".equals(land.get(i).get(j))) {
                    return t;
                }
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t + 1) {
                        boolean empty = ".".equals(land.get(x).get(y));
                        boolean dest = "D".equals(land.get(x).get(y));
                        if (empty || dest) {
                            vis[x][y] = true;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int m = land.size(), n = land[0].size();
        bool vis[m][n];
        int g[m][n];
        memset(vis, false, sizeof(vis));
        memset(g, 0x3f, sizeof(g));
        queue<pair<int, int>> q;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto c = land[i][j];
                if (c == "*") {
                    q.emplace(i, j);
                } else if (c == "S") {
                    si = i;
                    sj = j;
                }
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (int t = 0; !q.empty(); ++t) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                g[i][j] = t;
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        bool empty = land[x][y] == ".";
                        bool start = land[x][y] == "S";
                        if (empty || start) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        q.emplace(si, sj);
        memset(vis, false, sizeof(vis));
        vis[si][sj] = true;
        for (int t = 0; !q.empty(); ++t) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                if (land[i][j] == "D") {
                    return t;
                }
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t + 1) {
                        bool empty = land[x][y] == ".";
                        bool dest = land[x][y] == "D";
                        if (empty || dest) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSeconds(land [][]string) int {
	m, n := len(land), len(land[0])
	vis := make([][]bool, m)
	g := make([][]int, m)
	q := [][2]int{}
	var si, sj int
	for i, row := range land {
		vis[i] = make([]bool, n)
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = 1 << 30
		}
		for j, c := range row {
			if c == "*" {
				q = append(q, [2]int{i, j})
			} else if c == "S" {
				si, sj = i, j
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for t := 0; len(q) > 0; t++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, j := p[0], p[1]
			g[i][j] = t
			for d := 0; d < 4; d++ {
				x, y := i+dirs[d], j+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] {
					empty := land[x][y] == "."
					start := land[x][y] == "S"
					if empty || start {
						vis[x][y] = true
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	q = append(q, [2]int{si, sj})
	vis = make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	vis[si][sj] = true
	for t := 0; len(q) > 0; t++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, j := p[0], p[1]
			if land[i][j] == "D" {
				return t
			}
			for d := 0; d < 4; d++ {
				x, y := i+dirs[d], j+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t+1 {
					empty := land[x][y] == "."
					dest := land[x][y] == "D"
					if empty || dest {
						vis[x][y] = true
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSeconds(land: string[][]): number {
    const m = land.length;
    const n = land[0].length;
    const g: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(1 << 30));
    const vis: boolean[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(false));
    const q: number[][] = [];
    let [si, sj] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            const c = land[i][j];
            if (c === '*') {
                q.push([i, j]);
            } else if (c === 'S') {
                [si, sj] = [i, j];
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    for (let t = 0; q.length; ++t) {
        for (let k = q.length; k; --k) {
            const [i, j] = q.shift()!;
            g[i][j] = t;
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && 'S.'.includes(land[x][y])) {
                    vis[x][y] = true;
                    q.push([x, y]);
                }
            }
        }
    }
    q.push([si, sj]);
    for (let i = 0; i < m; ++i) {
        vis[i].fill(false);
    }
    vis[si][sj] = true;
    for (let t = 0; q.length; ++t) {
        for (let k = q.length; k; --k) {
            const [i, j] = q.shift()!;
            if (land[i][j] === 'D') {
                return t;
            }
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (
                    x >= 0 &&
                    x < m &&
                    y >= 0 &&
                    y < n &&
                    !vis[x][y] &&
                    g[x][y] > t + 1 &&
                    'D.'.includes(land[x][y]) &&
                    t + 1 < g[x][y]
                ) {
                    vis[x][y] = true;
                    q.push([x, y]);
                }
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个 <code>n * m</code> 的索引从 <strong>0</strong> 开始的二维字符串网格 <code>land</code>，目前你站在为&nbsp;<code>"S"</code> 的单元格上，你需要到达为&nbsp;<code>"D"</code> 的单元格。在这片区域上还有另外三种类型的单元格：</p>

<ul>
	<li><code>"."</code>：这些单元格是空的。</li>
	<li><code>"X"</code>：这些单元格是石头。</li>
	<li><code>"*"</code>：这些单元格被淹没了。</li>
</ul>

<p>每秒钟，你可以移动到与当前单元格共享边的单元格（如果它存在）。此外，每秒钟，与被淹没的单元格共享边的每个 <strong>空单元格</strong> 也会被淹没。</p>

<p>在你的旅程中，有两个需要注意的问题：</p>

<ul>
	<li>你不能踩在石头单元格上。</li>
	<li>你不能踩在被淹没的单元格上，因为你会淹死（同时，你也不能踩在在你踩上时会被淹没的单元格上）。</li>
</ul>

<p>返回从起始位置到达目标位置所需的 <strong>最小</strong> 时间（以秒为单位），如果不可能达到目标位置，则返回 <code>-1</code>。</p>

<p><strong>注意</strong>，目标位置永远不会被淹没。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>land = [["D",".","*"],[".",".","."],[".","S","."]]
<b>输出：</b>3
<strong>解释：</strong>下面的图片逐秒模拟了土地的变化。蓝色的单元格被淹没，灰色的单元格是石头。
 图片（0）显示了初始状态，图片（3）显示了当我们到达目标时的最终状态。正如你所看到的，我们需要 3 秒才能到达目标位置，答案是 3。
可以证明 3 是从 S 到 D 所需的最小时间。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2814.Minimum%20Time%20Takes%20to%20Reach%20Destination%20Without%20Drowning/images/ex1.png" style="padding: 5px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 600px; height: 111px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>land = [["D","X","*"],[".",".","."],[".",".","S"]]
<b>输出：</b>-1
<b>解释：</b>下面的图片逐秒模拟了土地的变化。蓝色的单元格被淹没，灰色的单元格是石头。
图片（0）显示了初始状态。正如你所看到的，无论我们选择哪条路径，我们都会在第三秒淹没。并且从 S 到 D 的最小路径需要 4 秒。
所以答案是 -1。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2814.Minimum%20Time%20Takes%20to%20Reach%20Destination%20Without%20Drowning/images/ex2-2.png" style="padding: 7px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 600px; height: 107px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>land = [["D",".",".",".","*","."],[".","X",".","X",".","."],[".",".",".",".","S","."]]
<b>输出：</b>6
<b>解释：</b>可以证明我们可以在 6 秒内到达目标位置。同时也可以证明 6 是从 S 到 D 所需的最小秒数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n, m &lt;= 100</code></li>
	<li><code>land</code>&nbsp;只由&nbsp;<code>"S"</code>, <code>"D"</code>, <code>"."</code>, <code>"*"</code> 和&nbsp;<code>"X"</code>&nbsp;组成。</li>
	<li><strong>恰好</strong>有一个单元格等于&nbsp;<code>"S"</code>。</li>
	<li><strong>恰好</strong>有一个单元格等于 <code>"D"</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 BFS

我们先跑一次 BFS，求出每个点到水域的最短距离，记录在数组 $g$ 中。然后再跑一次 BFS，从单元格 $(s_i, s_j)$ 出发，求出到达目标单元格 $(d_i, d_j)$ 的最短距离。在此过程中，如果当前单元格 $(i, j)$ 的相邻单元格 $(x, y)$ 满足 $g[x][y] \gt t + 1$，那么我们就可以从 $(x, y)$ 走到 $(i, j)$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是数组 $land$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSeconds(self, land: List[List[str]]) -> int:
        m, n = len(land), len(land[0])
        vis = [[False] * n for _ in range(m)]
        g = [[inf] * n for _ in range(m)]
        q = deque()
        si = sj = 0
        for i, row in enumerate(land):
            for j, c in enumerate(row):
                match c:
                    case "*":
                        q.append((i, j))
                    case "S":
                        si, sj = i, j
        dirs = (-1, 0, 1, 0, -1)
        t = 0
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                g[i][j] = t
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (
                        0 <= x < m
                        and 0 <= y < n
                        and not vis[x][y]
                        and land[x][y] in ".S"
                    ):
                        vis[x][y] = True
                        q.append((x, y))
            t += 1
        t = 0
        q = deque([(si, sj)])
        vis = [[False] * n for _ in range(m)]
        vis[si][sj] = True
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if land[i][j] == "D":
                    return t
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (
                        0 <= x < m
                        and 0 <= y < n
                        and g[x][y] > t + 1
                        and not vis[x][y]
                        and land[x][y] in ".D"
                    ):
                        vis[x][y] = True
                        q.append((x, y))
            t += 1
        return -1
```

#### Java

```java
class Solution {
    public int minimumSeconds(List<List<String>> land) {
        int m = land.size(), n = land.get(0).size();
        boolean[][] vis = new boolean[m][n];
        int[][] g = new int[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            Arrays.fill(g[i], 1 << 30);
            for (int j = 0; j < n; ++j) {
                String c = land.get(i).get(j);
                if ("*".equals(c)) {
                    q.offer(new int[] {i, j});
                } else if ("S".equals(c)) {
                    si = i;
                    sj = j;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; !q.isEmpty(); ++t) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                int i = p[0], j = p[1];
                g[i][j] = t;
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        boolean empty = ".".equals(land.get(x).get(y));
                        boolean start = "S".equals(land.get(x).get(y));
                        if (empty || start) {
                            vis[x][y] = true;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        q.offer(new int[] {si, sj});
        vis = new boolean[m][n];
        vis[si][sj] = true;
        for (int t = 0; !q.isEmpty(); ++t) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                int i = p[0], j = p[1];
                if ("D".equals(land.get(i).get(j))) {
                    return t;
                }
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t + 1) {
                        boolean empty = ".".equals(land.get(x).get(y));
                        boolean dest = "D".equals(land.get(x).get(y));
                        if (empty || dest) {
                            vis[x][y] = true;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int m = land.size(), n = land[0].size();
        bool vis[m][n];
        int g[m][n];
        memset(vis, false, sizeof(vis));
        memset(g, 0x3f, sizeof(g));
        queue<pair<int, int>> q;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto c = land[i][j];
                if (c == "*") {
                    q.emplace(i, j);
                } else if (c == "S") {
                    si = i;
                    sj = j;
                }
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (int t = 0; !q.empty(); ++t) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                g[i][j] = t;
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        bool empty = land[x][y] == ".";
                        bool start = land[x][y] == "S";
                        if (empty || start) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        q.emplace(si, sj);
        memset(vis, false, sizeof(vis));
        vis[si][sj] = true;
        for (int t = 0; !q.empty(); ++t) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                if (land[i][j] == "D") {
                    return t;
                }
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t + 1) {
                        bool empty = land[x][y] == ".";
                        bool dest = land[x][y] == "D";
                        if (empty || dest) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumSeconds(land [][]string) int {
	m, n := len(land), len(land[0])
	vis := make([][]bool, m)
	g := make([][]int, m)
	q := [][2]int{}
	var si, sj int
	for i, row := range land {
		vis[i] = make([]bool, n)
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = 1 << 30
		}
		for j, c := range row {
			if c == "*" {
				q = append(q, [2]int{i, j})
			} else if c == "S" {
				si, sj = i, j
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for t := 0; len(q) > 0; t++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, j := p[0], p[1]
			g[i][j] = t
			for d := 0; d < 4; d++ {
				x, y := i+dirs[d], j+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] {
					empty := land[x][y] == "."
					start := land[x][y] == "S"
					if empty || start {
						vis[x][y] = true
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	q = append(q, [2]int{si, sj})
	vis = make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	vis[si][sj] = true
	for t := 0; len(q) > 0; t++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, j := p[0], p[1]
			if land[i][j] == "D" {
				return t
			}
			for d := 0; d < 4; d++ {
				x, y := i+dirs[d], j+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t+1 {
					empty := land[x][y] == "."
					dest := land[x][y] == "D"
					if empty || dest {
						vis[x][y] = true
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumSeconds(land: string[][]): number {
    const m = land.length;
    const n = land[0].length;
    const g: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(1 << 30));
    const vis: boolean[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(false));
    const q: number[][] = [];
    let [si, sj] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            const c = land[i][j];
            if (c === '*') {
                q.push([i, j]);
            } else if (c === 'S') {
                [si, sj] = [i, j];
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    for (let t = 0; q.length; ++t) {
        for (let k = q.length; k; --k) {
            const [i, j] = q.shift()!;
            g[i][j] = t;
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && 'S.'.includes(land[x][y])) {
                    vis[x][y] = true;
                    q.push([x, y]);
                }
            }
        }
    }
    q.push([si, sj]);
    for (let i = 0; i < m; ++i) {
        vis[i].fill(false);
    }
    vis[si][sj] = true;
    for (let t = 0; q.length; ++t) {
        for (let k = q.length; k; --k) {
            const [i, j] = q.shift()!;
            if (land[i][j] === 'D') {
                return t;
            }
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (
                    x >= 0 &&
                    x < m &&
                    y >= 0 &&
                    y < n &&
                    !vis[x][y] &&
                    g[x][y] > t + 1 &&
                    'D.'.includes(land[x][y]) &&
                    t + 1 < g[x][y]
                ) {
                    vis[x][y] = true;
                    q.push([x, y]);
                }
            }
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2815. 数组中的最大数对和](https://leetcode.cn/problems/max-pair-sum-in-an-array){#2815}

{{< tabs "2815" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = -1
        for i, x in enumerate(nums):
            for y in nums[i + 1 :]:
                v = x + y
                if ans < v and max(str(x)) == max(str(y)):
                    ans = v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSum(int[] nums) {
        int ans = -1;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = nums[i] + nums[j];
                if (ans < v && f(nums[i]) == f(nums[j])) {
                    ans = v;
                }
            }
        }
        return ans;
    }

    private int f(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y = Math.max(y, x % 10);
        }
        return y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        auto f = [](int x) {
            int y = 0;
            for (; x; x /= 10) {
                y = max(y, x % 10);
            }
            return y;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = nums[i] + nums[j];
                if (ans < v && f(nums[i]) == f(nums[j])) {
                    ans = v;
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
func maxSum(nums []int) int {
	ans := -1
	f := func(x int) int {
		y := 0
		for ; x > 0; x /= 10 {
			y = max(y, x%10)
		}
		return y
	}
	for i, x := range nums {
		for _, y := range nums[i+1:] {
			if v := x + y; ans < v && f(x) == f(y) {
				ans = v
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSum(nums: number[]): number {
    const n = nums.length;
    let ans = -1;
    const f = (x: number): number => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y = Math.max(y, x % 10);
        }
        return y;
    };
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            const v = nums[i] + nums[j];
            if (ans < v && f(nums[i]) === f(nums[j])) {
                ans = v;
            }
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。请你从 <code>nums</code> 中找出和 <strong>最大</strong> 的一对数，且这两个数数位上最大的数字相等。</p>

<p>返回最大和，如果不存在满足题意的数字对，返回 <code>-1</code><em> 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [51,71,17,24,42]
<strong>输出：</strong>88
<strong>解释：</strong>
i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在数对满足数位上最大的数字相等。
</pre>

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

我们先初始化答案变量 $ans = -1$。接下来，直接枚举所有的数对 $(nums[i], nums[j])$，其中 $i \lt j$，并计算它们的和 $v = nums[i] + nums[j]$。如果 $v$ 比 $ans$ 更大，并且 $nums[i]$ 和 $nums[j]$ 的最大数字相同，那么我们就用 $v$ 更新 $ans$。

时间复杂度 $O(n^2 \times \log M)$，其中 $n$ 是数组的长度，而 $M$ 是数组中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = -1
        for i, x in enumerate(nums):
            for y in nums[i + 1 :]:
                v = x + y
                if ans < v and max(str(x)) == max(str(y)):
                    ans = v
        return ans
```

#### Java

```java
class Solution {
    public int maxSum(int[] nums) {
        int ans = -1;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = nums[i] + nums[j];
                if (ans < v && f(nums[i]) == f(nums[j])) {
                    ans = v;
                }
            }
        }
        return ans;
    }

    private int f(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y = Math.max(y, x % 10);
        }
        return y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        auto f = [](int x) {
            int y = 0;
            for (; x; x /= 10) {
                y = max(y, x % 10);
            }
            return y;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int v = nums[i] + nums[j];
                if (ans < v && f(nums[i]) == f(nums[j])) {
                    ans = v;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSum(nums []int) int {
	ans := -1
	f := func(x int) int {
		y := 0
		for ; x > 0; x /= 10 {
			y = max(y, x%10)
		}
		return y
	}
	for i, x := range nums {
		for _, y := range nums[i+1:] {
			if v := x + y; ans < v && f(x) == f(y) {
				ans = v
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxSum(nums: number[]): number {
    const n = nums.length;
    let ans = -1;
    const f = (x: number): number => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y = Math.max(y, x % 10);
        }
        return y;
    };
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            const v = nums[i] + nums[j];
            if (ans < v && f(nums[i]) === f(nums[j])) {
                ans = v;
            }
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

# [2816. 翻倍以链表形式表示的数字](https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list){#2816}

{{< tabs "2816" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head):
            dummy = ListNode()
            cur = head
            while cur:
                next = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = next
            return dummy.next

        head = reverse(head)
        dummy = cur = ListNode()
        mul, carry = 2, 0
        while head:
            x = head.val * mul + carry
            carry = x // 10
            cur.next = ListNode(x % 10)
            cur = cur.next
            head = head.next
        if carry:
            cur.next = ListNode(carry)
        return reverse(dummy.next)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        head = reverse(head);
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        int mul = 2, carry = 0;
        while (head != null) {
            int x = head.val * mul + carry;
            carry = x / 10;
            cur.next = new ListNode(x % 10);
            cur = cur.next;
            head = head.next;
        }
        if (carry > 0) {
            cur.next = new ListNode(carry);
        }
        return reverse(dummy.next);
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = next;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int mul = 2, carry = 0;
        while (head) {
            int x = head->val * mul + carry;
            carry = x / 10;
            cur->next = new ListNode(x % 10);
            cur = cur->next;
            head = head->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return reverse(dummy->next);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
	head = reverse(head)
	dummy := &ListNode{}
	cur := dummy
	mul, carry := 2, 0
	for head != nil {
		x := head.Val*mul + carry
		carry = x / 10
		cur.Next = &ListNode{Val: x % 10}
		cur = cur.Next
		head = head.Next
	}
	if carry > 0 {
		cur.Next = &ListNode{Val: carry}
	}
	return reverse(dummy.Next)
}

func reverse(head *ListNode) *ListNode {
	dummy := &ListNode{}
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = dummy.Next
		dummy.Next = cur
		cur = next
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function doubleIt(head: ListNode | null): ListNode | null {
    head = reverse(head);
    const dummy = new ListNode();
    let cur = dummy;
    let mul = 2;
    let carry = 0;
    while (head) {
        const x = head.val * mul + carry;
        carry = Math.floor(x / 10);
        cur.next = new ListNode(x % 10);
        cur = cur.next;
        head = head.next;
    }
    if (carry) {
        cur.next = new ListNode(carry);
    }
    return reverse(dummy.next);
}

function reverse(head: ListNode | null): ListNode | null {
    const dummy = new ListNode();
    let cur = head;
    while (cur) {
        const next = cur.next;
        cur.next = dummy.next;
        dummy.next = cur;
        cur = next;
    }
    return dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非空</strong> 链表的头节点 <code>head</code> ，表示一个不含前导零的非负数整数。</p>

<p>将链表 <strong>翻倍</strong> 后，返回头节点<em> </em><code>head</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2816.Double%20a%20Number%20Represented%20as%20a%20Linked%20List/images/example.png" style="width: 401px; height: 81px;" />
<pre>
<strong>输入：</strong>head = [1,8,9]
<strong>输出：</strong>[3,7,8]
<strong>解释：</strong>上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2816.Double%20a%20Number%20Represented%20as%20a%20Linked%20List/images/example2.png" style="width: 401px; height: 81px;" />
<pre>
<strong>输入：</strong>head = [9,9,9]
<strong>输出：</strong>[1,9,9,8]
<strong>解释：</strong>上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><font face="monospace"><code>0 &lt;= Node.val &lt;= 9</code></font></li>
	<li>生成的输入满足：链表表示一个不含前导零的数字，除了数字 <code>0</code> 本身。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：翻转链表 + 模拟

我们先将链表翻转，然后模拟乘法运算，最后再将链表翻转回来。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。忽略答案链表的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head):
            dummy = ListNode()
            cur = head
            while cur:
                next = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = next
            return dummy.next

        head = reverse(head)
        dummy = cur = ListNode()
        mul, carry = 2, 0
        while head:
            x = head.val * mul + carry
            carry = x // 10
            cur.next = ListNode(x % 10)
            cur = cur.next
            head = head.next
        if carry:
            cur.next = ListNode(carry)
        return reverse(dummy.next)
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        head = reverse(head);
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        int mul = 2, carry = 0;
        while (head != null) {
            int x = head.val * mul + carry;
            carry = x / 10;
            cur.next = new ListNode(x % 10);
            cur = cur.next;
            head = head.next;
        }
        if (carry > 0) {
            cur.next = new ListNode(carry);
        }
        return reverse(dummy.next);
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = next;
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int mul = 2, carry = 0;
        while (head) {
            int x = head->val * mul + carry;
            carry = x / 10;
            cur->next = new ListNode(x % 10);
            cur = cur->next;
            head = head->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return reverse(dummy->next);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
	head = reverse(head)
	dummy := &ListNode{}
	cur := dummy
	mul, carry := 2, 0
	for head != nil {
		x := head.Val*mul + carry
		carry = x / 10
		cur.Next = &ListNode{Val: x % 10}
		cur = cur.Next
		head = head.Next
	}
	if carry > 0 {
		cur.Next = &ListNode{Val: carry}
	}
	return reverse(dummy.Next)
}

func reverse(head *ListNode) *ListNode {
	dummy := &ListNode{}
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = dummy.Next
		dummy.Next = cur
		cur = next
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function doubleIt(head: ListNode | null): ListNode | null {
    head = reverse(head);
    const dummy = new ListNode();
    let cur = dummy;
    let mul = 2;
    let carry = 0;
    while (head) {
        const x = head.val * mul + carry;
        carry = Math.floor(x / 10);
        cur.next = new ListNode(x % 10);
        cur = cur.next;
        head = head.next;
    }
    if (carry) {
        cur.next = new ListNode(carry);
    }
    return reverse(dummy.next);
}

function reverse(head: ListNode | null): ListNode | null {
    const dummy = new ListNode();
    let cur = head;
    while (cur) {
        const next = cur.next;
        cur.next = dummy.next;
        dummy.next = cur;
        cur = next;
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2817. 限制条件下元素之间的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint){#2817}

{{< tabs "2817" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        sl = SortedList()
        ans = inf
        for i in range(x, len(nums)):
            sl.add(nums[i - x])
            j = bisect_left(sl, nums[i])
            if j < len(sl):
                ans = min(ans, sl[j] - nums[i])
            if j:
                ans = min(ans, nums[i] - sl[j - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minAbsoluteDifference(List<Integer> nums, int x) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int ans = 1 << 30;
        for (int i = x; i < nums.size(); ++i) {
            tm.merge(nums.get(i - x), 1, Integer::sum);
            Integer key = tm.ceilingKey(nums.get(i));
            if (key != null) {
                ans = Math.min(ans, key - nums.get(i));
            }
            key = tm.floorKey(nums.get(i));
            if (key != null) {
                ans = Math.min(ans, nums.get(i) - key);
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
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = 1 << 30;
        multiset<int> s;
        for (int i = x; i < nums.size(); ++i) {
            s.insert(nums[i - x]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) {
                ans = min(ans, *it - nums[i]);
            }
            if (it != s.begin()) {
                --it;
                ans = min(ans, nums[i] - *it);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAbsoluteDifference(nums []int, x int) int {
	rbt := redblacktree.NewWithIntComparator()
	ans := 1 << 30
	for i := x; i < len(nums); i++ {
		rbt.Put(nums[i-x], nil)
		c, _ := rbt.Ceiling(nums[i])
		f, _ := rbt.Floor(nums[i])
		if c != nil {
			ans = min(ans, c.Key.(int)-nums[i])
		}
		if f != nil {
			ans = min(ans, nums[i]-f.Key.(int))
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minAbsoluteDifference(nums: number[], x: number): number {
    const s = new TreeMultiSet<number>();
    const inf = 1 << 30;
    let ans = inf;
    for (let i = x; i < nums.length; ++i) {
        s.add(nums[i - x]);
        const c = s.ceil(nums[i]);
        const f = s.floor(nums[i]);
        if (c) {
            ans = Math.min(ans, c - nums[i]);
        }
        if (f) {
            ans = Math.min(ans, nums[i] - f);
        }
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>x</code>&nbsp;。</p>

<p>请你找到数组中下标距离至少为 <code>x</code>&nbsp;的两个元素的 <strong>差值绝对值</strong>&nbsp;的 <strong>最小值</strong>&nbsp;。</p>

<p>换言之，请你找到两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足&nbsp;<code>abs(i - j) &gt;= x</code> 且&nbsp;<code>abs(nums[i] - nums[j])</code>&nbsp;的值最小。</p>

<p>请你返回一个整数，表示下标距离至少为 <code>x</code>&nbsp;的两个元素之间的差值绝对值的 <strong>最小值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>nums = [4,3,2,4], x = 2
<b>输出：</b>0
<b>解释：</b>我们选择 nums[0] = 4 和 nums[3] = 4 。
它们下标距离满足至少为 2 ，差值绝对值为最小值 0 。
0 是最优解。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,3,2,10,15], x = 1
<b>输出：</b>1
<b>解释：</b>我们选择 nums[1] = 3 和 nums[2] = 2 。
它们下标距离满足至少为 1 ，差值绝对值为最小值 1 。
1 是最优解。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4], x = 3
<b>输出：</b>3
<strong>解释：</strong>我们选择 nums[0] = 1 和 nums[3] = 4 。
它们下标距离满足至少为 3 ，差值绝对值为最小值 3 。
3 是最优解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= x &lt; nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合

我们创建一个有序集合，用于存储距离当前下标至少为 $x$ 的元素。

接下来，我们从下标 $i = x$ 开始枚举，每次将 $nums[i - x]$ 加入到有序集合中。然后找出有序集合中与 $nums[i]$ 最接近的两个元素，它们的差值绝对值的最小值就是答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        sl = SortedList()
        ans = inf
        for i in range(x, len(nums)):
            sl.add(nums[i - x])
            j = bisect_left(sl, nums[i])
            if j < len(sl):
                ans = min(ans, sl[j] - nums[i])
            if j:
                ans = min(ans, nums[i] - sl[j - 1])
        return ans
```

#### Java

```java
class Solution {
    public int minAbsoluteDifference(List<Integer> nums, int x) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int ans = 1 << 30;
        for (int i = x; i < nums.size(); ++i) {
            tm.merge(nums.get(i - x), 1, Integer::sum);
            Integer key = tm.ceilingKey(nums.get(i));
            if (key != null) {
                ans = Math.min(ans, key - nums.get(i));
            }
            key = tm.floorKey(nums.get(i));
            if (key != null) {
                ans = Math.min(ans, nums.get(i) - key);
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
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = 1 << 30;
        multiset<int> s;
        for (int i = x; i < nums.size(); ++i) {
            s.insert(nums[i - x]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) {
                ans = min(ans, *it - nums[i]);
            }
            if (it != s.begin()) {
                --it;
                ans = min(ans, nums[i] - *it);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minAbsoluteDifference(nums []int, x int) int {
	rbt := redblacktree.NewWithIntComparator()
	ans := 1 << 30
	for i := x; i < len(nums); i++ {
		rbt.Put(nums[i-x], nil)
		c, _ := rbt.Ceiling(nums[i])
		f, _ := rbt.Floor(nums[i])
		if c != nil {
			ans = min(ans, c.Key.(int)-nums[i])
		}
		if f != nil {
			ans = min(ans, nums[i]-f.Key.(int))
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minAbsoluteDifference(nums: number[], x: number): number {
    const s = new TreeMultiSet<number>();
    const inf = 1 << 30;
    let ans = inf;
    for (let i = x; i < nums.length; ++i) {
        s.add(nums[i - x]);
        const c = s.ceil(nums[i]);
        const f = s.floor(nums[i]);
        if (c) {
            ans = Math.min(ans, c - nums[i]);
        }
        if (f) {
            ans = Math.min(ans, nums[i] - f);
        }
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score){#2818}

{{< tabs "2818" >}}

{{% tab "python" %}}
```python
def primeFactors(n):
    i = 2
    ans = set()
    while i * i <= n:
        while n % i == 0:
            ans.add(i)
            n //= i
        i += 1
    if n > 1:
        ans.add(n)
    return len(ans)


class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        arr = [(i, primeFactors(x), x) for i, x in enumerate(nums)]
        n = len(nums)

        left = [-1] * n
        right = [n] * n
        stk = []
        for i, f, x in arr:
            while stk and stk[-1][0] < f:
                stk.pop()
            if stk:
                left[i] = stk[-1][1]
            stk.append((f, i))

        stk = []
        for i, f, x in arr[::-1]:
            while stk and stk[-1][0] <= f:
                stk.pop()
            if stk:
                right[i] = stk[-1][1]
            stk.append((f, i))

        arr.sort(key=lambda x: -x[2])
        ans = 1
        for i, f, x in arr:
            l, r = left[i], right[i]
            cnt = (i - l) * (r - i)
            if cnt <= k:
                ans = ans * pow(x, cnt, mod) % mod
                k -= cnt
            else:
                ans = ans * pow(x, k, mod) % mod
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {i, primeFactors(nums.get(i)), nums.get(i)};
        }
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int[] e : arr) {
            int i = e[0], f = e[1];
            while (!stk.isEmpty() && arr[stk.peek()][1] < f) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int f = arr[i][1];
            while (!stk.isEmpty() && arr[stk.peek()][1] <= f) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        Arrays.sort(arr, (a, b) -> b[2] - a[2]);
        long ans = 1;
        for (int[] e : arr) {
            int i = e[0], x = e[2];
            int l = left[i], r = right[i];
            long cnt = (long) (i - l) * (r - i);
            if (cnt <= k) {
                ans = ans * qpow(x, cnt) % mod;
                k -= cnt;
            } else {
                ans = ans * qpow(x, k) % mod;
                break;
            }
        }
        return (int) ans;
    }

    private int primeFactors(int n) {
        int i = 2;
        Set<Integer> ans = new HashSet<>();
        while (i <= n / i) {
            while (n % i == 0) {
                ans.add(i);
                n /= i;
            }
            ++i;
        }
        if (n > 1) {
            ans.add(n);
        }
        return ans.size();
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<tuple<int, int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {i, primeFactors(nums[i]), nums[i]};
        }
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (auto [i, f, _] : arr) {
            while (!stk.empty() && get<1>(arr[stk.top()]) < f) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int f = get<1>(arr[i]);
            while (!stk.empty() && get<1>(arr[stk.top()]) <= f) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) {
            return get<2>(rhs) < get<2>(lhs);
        });
        long long ans = 1;
        auto qpow = [&](long long a, int n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        for (auto [i, _, x] : arr) {
            int l = left[i], r = right[i];
            long long cnt = 1LL * (i - l) * (r - i);
            if (cnt <= k) {
                ans = ans * qpow(x, cnt) % mod;
                k -= cnt;
            } else {
                ans = ans * qpow(x, k) % mod;
                break;
            }
        }
        return ans;
    }

    int primeFactors(int n) {
        int i = 2;
        unordered_set<int> ans;
        while (i <= n / i) {
            while (n % i == 0) {
                ans.insert(i);
                n /= i;
            }
            ++i;
        }
        if (n > 1) {
            ans.insert(n);
        }
        return ans.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumScore(nums []int, k int) int {
	n := len(nums)
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	arr := make([][3]int, n)
	left := make([]int, n)
	right := make([]int, n)
	for i, x := range nums {
		left[i] = -1
		right[i] = n
		arr[i] = [3]int{i, primeFactors(x), x}
	}
	stk := []int{}
	for _, e := range arr {
		i, f := e[0], e[1]
		for len(stk) > 0 && arr[stk[len(stk)-1]][1] < f {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		f := arr[i][1]
		for len(stk) > 0 && arr[stk[len(stk)-1]][1] <= f {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][2] > arr[j][2] })
	ans := 1
	for _, e := range arr {
		i, x := e[0], e[2]
		l, r := left[i], right[i]
		cnt := (i - l) * (r - i)
		if cnt <= k {
			ans = ans * qpow(x, cnt) % mod
			k -= cnt
		} else {
			ans = ans * qpow(x, k) % mod
			break
		}
	}
	return ans
}

func primeFactors(n int) int {
	i := 2
	ans := map[int]bool{}
	for i <= n/i {
		for n%i == 0 {
			ans[i] = true
			n /= i
		}
		i++
	}
	if n > 1 {
		ans[n] = true
	}
	return len(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumScore(nums: number[], k: number): number {
    const mod = 10 ** 9 + 7;
    const n = nums.length;
    const arr: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        arr[i] = [i, primeFactors(nums[i]), nums[i]];
    }
    const stk: number[] = [];
    for (const [i, f, _] of arr) {
        while (stk.length && arr[stk.at(-1)!][1] < f) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        const f = arr[i][1];
        while (stk.length && arr[stk.at(-1)!][1] <= f) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    arr.sort((a, b) => b[2] - a[2]);
    let ans = 1n;
    for (const [i, _, x] of arr) {
        const l = left[i];
        const r = right[i];
        const cnt = (i - l) * (r - i);
        if (cnt <= k) {
            ans = (ans * qpow(BigInt(x), cnt, mod)) % BigInt(mod);
            k -= cnt;
        } else {
            ans = (ans * qpow(BigInt(x), k, mod)) % BigInt(mod);
            break;
        }
    }
    return Number(ans);
}

function primeFactors(n: number): number {
    let i = 2;
    const s: Set<number> = new Set();
    while (i * i <= n) {
        while (n % i === 0) {
            s.add(i);
            n = Math.floor(n / i);
        }
        ++i;
    }
    if (n > 1) {
        s.add(n);
    }
    return s.size;
}

function qpow(a: bigint, n: number, mod: number): bigint {
    let ans = 1n;
    for (; n; n >>>= 1) {
        if (n & 1) {
            ans = (ans * a) % BigInt(mod);
        }
        a = (a * a) % BigInt(mod);
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

<p>给你一个长度为 <code>n</code>&nbsp;的正整数数组&nbsp;<code>nums</code>&nbsp;和一个整数 <code>k</code>&nbsp;。</p>

<p>一开始，你的分数为 <code>1</code>&nbsp;。你可以进行以下操作至多 <code>k</code>&nbsp;次，目标是使你的分数最大：</p>

<ul>
	<li>选择一个之前没有选过的 <strong>非空</strong>&nbsp;子数组&nbsp;<code>nums[l, ..., r]</code>&nbsp;。</li>
	<li>从&nbsp;<code>nums[l, ..., r]</code>&nbsp;里面选择一个 <strong>质数分数</strong>&nbsp;最高的元素 <code>x</code>&nbsp;。如果多个元素质数分数相同且最高，选择下标最小的一个。</li>
	<li>将你的分数乘以&nbsp;<code>x</code>&nbsp;。</li>
</ul>

<p><code>nums[l, ..., r]</code>&nbsp;表示&nbsp;<code>nums</code>&nbsp;中起始下标为&nbsp;<code>l</code>&nbsp;，结束下标为 <code>r</code>&nbsp;的子数组，两个端点都包含。</p>

<p>一个整数的 <strong>质数分数</strong>&nbsp;等于&nbsp;<code>x</code>&nbsp;不同质因子的数目。比方说，&nbsp;<code>300</code>&nbsp;的质数分数为&nbsp;<code>3</code>&nbsp;，因为&nbsp;<code>300 = 2 * 2 * 3 * 5 * 5</code>&nbsp;。</p>

<p>请你返回进行至多 <code>k</code>&nbsp;次操作后，可以得到的 <strong>最大分数</strong>&nbsp;。</p>

<p>由于答案可能很大，请你将结果对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [8,3,9,3,8], k = 2
<b>输出：</b>81
<b>解释：</b>进行以下操作可以得到分数 81 ：
- 选择子数组 nums[2, ..., 2] 。nums[2] 是子数组中唯一的元素。所以我们将分数乘以 nums[2] ，分数变为 1 * 9 = 9 。
- 选择子数组 nums[2, ..., 3] 。nums[2] 和 nums[3] 质数分数都为 1 ，但是 nums[2] 下标更小。所以我们将分数乘以 nums[2] ，分数变为 9 * 9 = 81 。
81 是可以得到的最高得分。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [19,12,14,6,10,18], k = 3
<b>输出：</b>4788
<b>解释：</b>进行以下操作可以得到分数 4788 ：
- 选择子数组 nums[0, ..., 0] 。nums[0] 是子数组中唯一的元素。所以我们将分数乘以 nums[0] ，分数变为 1 * 19 = 19 。
- 选择子数组 nums[5, ..., 5] 。nums[5] 是子数组中唯一的元素。所以我们将分数乘以 nums[5] ，分数变为 19 * 18 = 342 。
- 选择子数组 nums[2, ..., 3] 。nums[2] 和 nums[3] 质数分数都为 2，但是 nums[2] 下标更小。所以我们将分数乘以 nums[2] ，分数变为  342 * 14 = 4788 。
4788 是可以得到的最高的分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(n * (n + 1) / 2, 10<sup>9</sup>)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈 + 排序贪心

我们不妨考虑枚举每个元素 $nums[i]$ 作为质数分数最高的元素，那么我们需要找出左边第一个质数分数大于等于当前元素的位置 $l$，以及右边第一个质数分数大于当前元素的位置 $r$，那么以当前元素为最高质数分数的子数组有 $cnt = (i - l) \times (r - i)$ 个，它对答案的贡献为 $nums[i]^{cnt}$。

而题目限制了最多进行 $k$ 次操作，我们可以贪心地从大到小枚举 $nums[i]$，每一次算出其子数组的个数 $cnt$，如果 $cnt \le k$，那么 $nums[i]$ 对答案的贡献就是 $nums[i]^{cnt}$，然后我们更新 $k = k - cnt$，继续枚举下一个元素。如果 $cnt \gt k$，那么 $nums[i]$ 对答案的贡献就是 $nums[i]^{k}$，然后退出循环。

枚举结束，返回答案即可。注意，由于幂次较大，我们需要用到快速幂。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
def primeFactors(n):
    i = 2
    ans = set()
    while i * i <= n:
        while n % i == 0:
            ans.add(i)
            n //= i
        i += 1
    if n > 1:
        ans.add(n)
    return len(ans)


class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        arr = [(i, primeFactors(x), x) for i, x in enumerate(nums)]
        n = len(nums)

        left = [-1] * n
        right = [n] * n
        stk = []
        for i, f, x in arr:
            while stk and stk[-1][0] < f:
                stk.pop()
            if stk:
                left[i] = stk[-1][1]
            stk.append((f, i))

        stk = []
        for i, f, x in arr[::-1]:
            while stk and stk[-1][0] <= f:
                stk.pop()
            if stk:
                right[i] = stk[-1][1]
            stk.append((f, i))

        arr.sort(key=lambda x: -x[2])
        ans = 1
        for i, f, x in arr:
            l, r = left[i], right[i]
            cnt = (i - l) * (r - i)
            if cnt <= k:
                ans = ans * pow(x, cnt, mod) % mod
                k -= cnt
            else:
                ans = ans * pow(x, k, mod) % mod
                break
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {i, primeFactors(nums.get(i)), nums.get(i)};
        }
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int[] e : arr) {
            int i = e[0], f = e[1];
            while (!stk.isEmpty() && arr[stk.peek()][1] < f) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int f = arr[i][1];
            while (!stk.isEmpty() && arr[stk.peek()][1] <= f) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        Arrays.sort(arr, (a, b) -> b[2] - a[2]);
        long ans = 1;
        for (int[] e : arr) {
            int i = e[0], x = e[2];
            int l = left[i], r = right[i];
            long cnt = (long) (i - l) * (r - i);
            if (cnt <= k) {
                ans = ans * qpow(x, cnt) % mod;
                k -= cnt;
            } else {
                ans = ans * qpow(x, k) % mod;
                break;
            }
        }
        return (int) ans;
    }

    private int primeFactors(int n) {
        int i = 2;
        Set<Integer> ans = new HashSet<>();
        while (i <= n / i) {
            while (n % i == 0) {
                ans.add(i);
                n /= i;
            }
            ++i;
        }
        if (n > 1) {
            ans.add(n);
        }
        return ans.size();
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<tuple<int, int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {i, primeFactors(nums[i]), nums[i]};
        }
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (auto [i, f, _] : arr) {
            while (!stk.empty() && get<1>(arr[stk.top()]) < f) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int f = get<1>(arr[i]);
            while (!stk.empty() && get<1>(arr[stk.top()]) <= f) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) {
            return get<2>(rhs) < get<2>(lhs);
        });
        long long ans = 1;
        auto qpow = [&](long long a, int n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        for (auto [i, _, x] : arr) {
            int l = left[i], r = right[i];
            long long cnt = 1LL * (i - l) * (r - i);
            if (cnt <= k) {
                ans = ans * qpow(x, cnt) % mod;
                k -= cnt;
            } else {
                ans = ans * qpow(x, k) % mod;
                break;
            }
        }
        return ans;
    }

    int primeFactors(int n) {
        int i = 2;
        unordered_set<int> ans;
        while (i <= n / i) {
            while (n % i == 0) {
                ans.insert(i);
                n /= i;
            }
            ++i;
        }
        if (n > 1) {
            ans.insert(n);
        }
        return ans.size();
    }
};
```

#### Go

```go
func maximumScore(nums []int, k int) int {
	n := len(nums)
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	arr := make([][3]int, n)
	left := make([]int, n)
	right := make([]int, n)
	for i, x := range nums {
		left[i] = -1
		right[i] = n
		arr[i] = [3]int{i, primeFactors(x), x}
	}
	stk := []int{}
	for _, e := range arr {
		i, f := e[0], e[1]
		for len(stk) > 0 && arr[stk[len(stk)-1]][1] < f {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		f := arr[i][1]
		for len(stk) > 0 && arr[stk[len(stk)-1]][1] <= f {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][2] > arr[j][2] })
	ans := 1
	for _, e := range arr {
		i, x := e[0], e[2]
		l, r := left[i], right[i]
		cnt := (i - l) * (r - i)
		if cnt <= k {
			ans = ans * qpow(x, cnt) % mod
			k -= cnt
		} else {
			ans = ans * qpow(x, k) % mod
			break
		}
	}
	return ans
}

func primeFactors(n int) int {
	i := 2
	ans := map[int]bool{}
	for i <= n/i {
		for n%i == 0 {
			ans[i] = true
			n /= i
		}
		i++
	}
	if n > 1 {
		ans[n] = true
	}
	return len(ans)
}
```

#### TypeScript

```ts
function maximumScore(nums: number[], k: number): number {
    const mod = 10 ** 9 + 7;
    const n = nums.length;
    const arr: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        arr[i] = [i, primeFactors(nums[i]), nums[i]];
    }
    const stk: number[] = [];
    for (const [i, f, _] of arr) {
        while (stk.length && arr[stk.at(-1)!][1] < f) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        const f = arr[i][1];
        while (stk.length && arr[stk.at(-1)!][1] <= f) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    arr.sort((a, b) => b[2] - a[2]);
    let ans = 1n;
    for (const [i, _, x] of arr) {
        const l = left[i];
        const r = right[i];
        const cnt = (i - l) * (r - i);
        if (cnt <= k) {
            ans = (ans * qpow(BigInt(x), cnt, mod)) % BigInt(mod);
            k -= cnt;
        } else {
            ans = (ans * qpow(BigInt(x), k, mod)) % BigInt(mod);
            break;
        }
    }
    return Number(ans);
}

function primeFactors(n: number): number {
    let i = 2;
    const s: Set<number> = new Set();
    while (i * i <= n) {
        while (n % i === 0) {
            s.add(i);
            n = Math.floor(n / i);
        }
        ++i;
    }
    if (n > 1) {
        s.add(n);
    }
    return s.size;
}

function qpow(a: bigint, n: number, mod: number): bigint {
    let ans = 1n;
    for (; n; n >>>= 1) {
        if (n & 1) {
            ans = (ans * a) % BigInt(mod);
        }
        a = (a * a) % BigInt(mod);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2819. 购买巧克力后的最小相对损失 🔒](https://leetcode.cn/problems/minimum-relative-loss-after-buying-chocolates){#2819}

{{< tabs "2819" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRelativeLosses(
        self, prices: List[int], queries: List[List[int]]
    ) -> List[int]:
        def f(k: int, m: int) -> int:
            l, r = 0, min(m, bisect_right(prices, k))
            while l < r:
                mid = (l + r) >> 1
                right = m - mid
                if prices[mid] < 2 * k - prices[n - right]:
                    l = mid + 1
                else:
                    r = mid
            return l

        prices.sort()
        s = list(accumulate(prices, initial=0))
        ans = []
        n = len(prices)
        for k, m in queries:
            l = f(k, m)
            r = m - l
            loss = s[l] + 2 * k * r - (s[n] - s[n - r])
            ans.append(loss)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] prices;

    public long[] minimumRelativeLosses(int[] prices, int[][] queries) {
        n = prices.length;
        Arrays.sort(prices);
        this.prices = prices;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + prices[i];
        }
        int q = queries.length;
        long[] ans = new long[q];
        for (int i = 0; i < q; ++i) {
            int k = queries[i][0], m = queries[i][1];
            int l = f(k, m);
            int r = m - l;
            ans[i] = s[l] + 2L * k * r - (s[n] - s[n - r]);
        }
        return ans;
    }

    private int f(int k, int m) {
        int l = 0, r = Arrays.binarySearch(prices, k);
        if (r < 0) {
            r = -(r + 1);
        }
        r = Math.min(m, r);
        while (l < r) {
            int mid = (l + r) >> 1;
            int right = m - mid;
            if (prices[mid] < 2L * k - prices[n - right]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + prices[i - 1];
        }
        auto f = [&](int k, int m) {
            int l = 0, r = upper_bound(prices.begin(), prices.end(), k) - prices.begin();
            r = min(r, m);
            while (l < r) {
                int mid = (l + r) >> 1;
                int right = m - mid;
                if (prices[mid] < 2LL * k - prices[n - right]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };
        vector<long long> ans;
        for (auto& q : queries) {
            int k = q[0], m = q[1];
            int l = f(k, m);
            int r = m - l;
            ans.push_back(s[l] + 2LL * k * r - (s[n] - s[n - r]));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRelativeLosses(prices []int, queries [][]int) []int64 {
	n := len(prices)
	sort.Ints(prices)
	s := make([]int, n+1)
	for i, x := range prices {
		s[i+1] = s[i] + x
	}
	f := func(k, m int) int {
		l, r := 0, sort.Search(n, func(i int) bool { return prices[i] > k })
		if r > m {
			r = m
		}
		for l < r {
			mid := (l + r) >> 1
			right := m - mid
			if prices[mid] < 2*k-prices[n-right] {
				l = mid + 1
			} else {
				r = mid
			}
		}
		return l
	}
	ans := make([]int64, len(queries))
	for i, q := range queries {
		k, m := q[0], q[1]
		l := f(k, m)
		r := m - l
		ans[i] = int64(s[l] + 2*k*r - (s[n] - s[n-r]))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRelativeLosses(prices: number[], queries: number[][]): number[] {
    const n = prices.length;
    prices.sort((a, b) => a - b);
    const s: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + prices[i];
    }

    const search = (x: number): number => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (prices[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    const f = (k: number, m: number): number => {
        let l = 0;
        let r = Math.min(search(k), m);
        while (l < r) {
            const mid = (l + r) >> 1;
            const right = m - mid;
            if (prices[mid] < 2 * k - prices[n - right]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const [k, m] of queries) {
        const l = f(k, m);
        const r = m - l;
        ans.push(s[l] + 2 * k * r - (s[n] - s[n - r]));
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

<p>现给定一个整数数组 <code>prices</code>，表示巧克力的价格；以及一个二维整数数组 <code>queries</code>，其中 <code>queries[i] = [ki, mi]</code>。</p>

<p>Alice 和 Bob 去买巧克力，Alice 提出了一种付款方式，而 Bob 同意了。</p>

<p>对于每个 <code>queries[i]</code> ，它的条件如下：</p>

<ul>
	<li>如果一块巧克力的价格 <strong>小于等于</strong> <code>ki</code>，那么 Bob 为它付款。</li>
	<li>否则，Bob 为其中 <code>ki</code> 部分付款，而 Alice 为 <strong>剩余</strong> 部分付款。</li>
</ul>

<p>Bob 想要选择 <strong>恰好</strong> <code>mi</code> 块巧克力，使得他的 <strong>相对损失最小</strong> 。更具体地说，如果总共 Alice 付款了 <code>ai</code>，Bob 付款了 <code>bi</code>，那么 Bob 希望最小化 <code>bi - ai</code>。</p>

<p>返回一个整数数组 <code>ans</code>，其中 <code>ans[i]</code> 是 Bob 在&nbsp;<code>queries[i]</code> 中可能的 <strong>最小相对损失</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>prices = [1,9,22,10,19], queries = [[18,4],[5,2]]
<b>输出：</b>[34,-21]
<b>解释：</b>对于第一个 query，Bob 选择价格为 [1,9,10,22] 的巧克力。他付了 1 + 9 + 10 + 18 = 38，Alice 付了 0 + 0 + 0 + 4 = 4。因此，Bob 的相对损失是 38 - 4 = 34。
对于第二个 query，Bob 选择价格为 [19,22] 的巧克力。他付了 5 + 5 = 10，Alice 付了 14 + 17 = 31。因此，Bob 的相对损失是 10 - 31 = -21。
可以证明这些是可能的最小相对损失。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>prices = [1,5,4,3,7,11,9], queries = [[5,4],[5,7],[7,3],[4,5]]
<b>输出：</b>[4,16,7,1]
<b>解释：</b>对于第一个 query，Bob 选择价格为 [1,3,9,11] 的巧克力。他付了 1 + 3 + 5 + 5 = 14，Alice 付了 0 + 0 + 4 + 6 = 10。因此，Bob 的相对损失是 14 - 10 = 4。
对于第二个 query，Bob 必须选择所有的巧克力。他付了 1 + 5 + 4 + 3 + 5 + 5 + 5 = 28，Alice 付了 0 + 0 + 0 + 0 + 2 + 6 + 4 = 12。因此，Bob 的相对损失是 28 - 12 = 16。
对于第三个 query，Bob 选择价格为 [1,3,11] 的巧克力。他付了 1 + 3 + 7 = 11，Alice 付了 0 + 0 + 4 = 4。因此，Bob 的相对损失是 11 - 4 = 7。
对于第四个 query，Bob 选择价格为 [1,3,7,9,11] 的巧克力。他付了 1 + 3 + 4 + 4 + 4 = 16，Alice 付了 0 + 0 + 3 + 5 + 7 = 15。因此，Bob 的相对损失是 16 - 15 = 1。
可以证明这些是可能的最小相对损失。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>prices = [5,6,7], queries = [[10,1],[5,3],[3,3]]
<b>输出：</b>[5,12,0]
<b>解释：</b>对于第一个 query，Bob 选择价格为 5 的巧克力。他付了 5，Alice 付了 0。因此，Bob 的相对损失是 5 - 0 = 5。
对于第二个 query，Bob 必须选择所有的巧克力。他付了 5 + 5 + 5 = 15，Alice 付了 0 + 1 + 2 = 3。因此，Bob 的相对损失是 15 - 3 = 12。
对于第三个 query，Bob 必须选择所有的巧克力。他付了 3 + 3 + 3 = 9，Alice 付了 2 + 3 + 4 = 9。因此，Bob 的相对损失是 9 - 9 = 0。
可以证明这些是可能的最小相对损失。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= k<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m<sub>i</sub> &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找 + 前缀和

根据题目描述，我们可以知道：

如果 $prices[i] \leq k$，那么 Bob 需要支付 $prices[i]$，而 Alice 不需要支付。因此 Bob 的相对损失为 $prices[i]$。在这种情况下，Bob 应该选择价格较低的巧克力，才能最小化相对损失。

如果 $prices[i] \gt k$，那么 Bob 需要支付 $k$，而 Alice 需要支付 $prices[i] - k$。因此 Bob 的相对损失为 $k - (prices[i] - k) = 2k - prices[i]$。在这种情况下，Bob 应该选择价格较高的巧克力，才能最小化相对损失。

因此，我们先对价格数组 $prices$ 进行排序，然后预处理出前缀和数组 $s$，其中 $s[i]$ 表示前 $i$ 个巧克力的价格之和。

接下来，对于每个询问 $[k, m]$，我们先使用二分查找，找到第一个价格大于 $k$ 的巧克力的下标 $r$。然后，再利用二分查找，找到左侧应该选择的巧克力的数量 $l$，那么右侧应该选择的巧克力的数量就是 $m - l$。此时，Bob 的相对损失为 $s[l] + 2k(m - l) - (s[n] - s[n - (m - l)])$。

上述第二次二分查找的过程中，我们需要判断 $prices[mid] \lt 2k - prices[n - (m - mid)]$，其中 $right$ 表示右侧应该选择的巧克力的数量。如果该不等式成立，那么说明选择 $mid$ 位置的巧克力的相对损失较低，此时更新 $l = mid + 1$。否则，说明 $mid$ 位置的巧克力的相对损失较高，此时更新 $r = mid$。

时间复杂度 $O((n + m) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $prices$ 和 $queries$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRelativeLosses(
        self, prices: List[int], queries: List[List[int]]
    ) -> List[int]:
        def f(k: int, m: int) -> int:
            l, r = 0, min(m, bisect_right(prices, k))
            while l < r:
                mid = (l + r) >> 1
                right = m - mid
                if prices[mid] < 2 * k - prices[n - right]:
                    l = mid + 1
                else:
                    r = mid
            return l

        prices.sort()
        s = list(accumulate(prices, initial=0))
        ans = []
        n = len(prices)
        for k, m in queries:
            l = f(k, m)
            r = m - l
            loss = s[l] + 2 * k * r - (s[n] - s[n - r])
            ans.append(loss)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int[] prices;

    public long[] minimumRelativeLosses(int[] prices, int[][] queries) {
        n = prices.length;
        Arrays.sort(prices);
        this.prices = prices;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + prices[i];
        }
        int q = queries.length;
        long[] ans = new long[q];
        for (int i = 0; i < q; ++i) {
            int k = queries[i][0], m = queries[i][1];
            int l = f(k, m);
            int r = m - l;
            ans[i] = s[l] + 2L * k * r - (s[n] - s[n - r]);
        }
        return ans;
    }

    private int f(int k, int m) {
        int l = 0, r = Arrays.binarySearch(prices, k);
        if (r < 0) {
            r = -(r + 1);
        }
        r = Math.min(m, r);
        while (l < r) {
            int mid = (l + r) >> 1;
            int right = m - mid;
            if (prices[mid] < 2L * k - prices[n - right]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + prices[i - 1];
        }
        auto f = [&](int k, int m) {
            int l = 0, r = upper_bound(prices.begin(), prices.end(), k) - prices.begin();
            r = min(r, m);
            while (l < r) {
                int mid = (l + r) >> 1;
                int right = m - mid;
                if (prices[mid] < 2LL * k - prices[n - right]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };
        vector<long long> ans;
        for (auto& q : queries) {
            int k = q[0], m = q[1];
            int l = f(k, m);
            int r = m - l;
            ans.push_back(s[l] + 2LL * k * r - (s[n] - s[n - r]));
        }
        return ans;
    }
};
```

#### Go

```go
func minimumRelativeLosses(prices []int, queries [][]int) []int64 {
	n := len(prices)
	sort.Ints(prices)
	s := make([]int, n+1)
	for i, x := range prices {
		s[i+1] = s[i] + x
	}
	f := func(k, m int) int {
		l, r := 0, sort.Search(n, func(i int) bool { return prices[i] > k })
		if r > m {
			r = m
		}
		for l < r {
			mid := (l + r) >> 1
			right := m - mid
			if prices[mid] < 2*k-prices[n-right] {
				l = mid + 1
			} else {
				r = mid
			}
		}
		return l
	}
	ans := make([]int64, len(queries))
	for i, q := range queries {
		k, m := q[0], q[1]
		l := f(k, m)
		r := m - l
		ans[i] = int64(s[l] + 2*k*r - (s[n] - s[n-r]))
	}
	return ans
}
```

#### TypeScript

```ts
function minimumRelativeLosses(prices: number[], queries: number[][]): number[] {
    const n = prices.length;
    prices.sort((a, b) => a - b);
    const s: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + prices[i];
    }

    const search = (x: number): number => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (prices[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    const f = (k: number, m: number): number => {
        let l = 0;
        let r = Math.min(search(k), m);
        while (l < r) {
            const mid = (l + r) >> 1;
            const right = m - mid;
            if (prices[mid] < 2 * k - prices[n - right]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const [k, m] of queries) {
        const l = f(k, m);
        const r = m - l;
        ans.push(s[l] + 2 * k * r - (s[n] - s[n - r]));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
