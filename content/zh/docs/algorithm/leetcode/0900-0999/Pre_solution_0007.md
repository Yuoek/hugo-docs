---
title: "0960_删列造序 III"
date: 2025-10-08T18:36:43+08:00
weight: 7
tags: [二叉树, 几何, 动态规划, 单调栈, 双指针, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数组, 栈, 树, 深度优先搜索, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [0960_删列造序 III](#960)
#### [数组](#960)
#### [字符串](#960)
#### [动态规划](#960)
### [0961_在长度 2N 的数组中找出重复 N 次的元素](#961)
#### [数组](#961)
#### [哈希表](#961)
### [0962_最大宽度坡](#962)
#### [栈](#962)
#### [数组](#962)
#### [双指针](#962)
#### [单调栈](#962)
### [0963_最小面积矩形 II](#963)
#### [几何](#963)
#### [数组](#963)
#### [哈希表](#963)
#### [数学](#963)
### [0964_表示数字的最少运算符](#964)
#### [记忆化搜索](#964)
#### [数学](#964)
#### [动态规划](#964)
### [0965_单值二叉树](#965)
#### [树](#965)
#### [深度优先搜索](#965)
#### [广度优先搜索](#965)
#### [二叉树](#965)
### [0966_元音拼写检查器](#966)
#### [数组](#966)
#### [哈希表](#966)
#### [字符串](#966)
### [0967_连续差相同的数字](#967)
#### [广度优先搜索](#967)
#### [回溯](#967)
### [0968_监控二叉树](#968)
#### [树](#968)
#### [深度优先搜索](#968)
#### [动态规划](#968)
#### [二叉树](#968)
### [0969_煎饼排序](#969)
#### [贪心](#969)
#### [数组](#969)
#### [双指针](#969)
#### [排序](#969)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0960_删列造序 III
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 0961_在长度 2N 的数组中找出重复 N 次的元素
___
#### 数组
___
#### 哈希表
---
### 0962_最大宽度坡
___
#### 栈
___
#### 数组
___
#### 双指针
___
#### 单调栈
---
### 0963_最小面积矩形 II
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 0964_表示数字的最少运算符
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
---
### 0965_单值二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0966_元音拼写检查器
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0967_连续差相同的数字
___
#### 广度优先搜索
___
#### 回溯
---
### 0968_监控二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 二叉树
---
### 0969_煎饼排序
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 几何 | 动态规划 |
| 单调栈 | 双指针 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 栈 | 树 | 深度优先搜索 |
| 记忆化搜索 | 贪心 |  |

# [960. 删列造序 III](https://leetcode.cn/problems/delete-columns-to-make-sorted-iii){#960}

{{< tabs "960" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs[0])
        f = [1] * n
        for i in range(n):
            for j in range(i):
                if all(s[j] <= s[i] for s in strs):
                    f[i] = max(f[i], f[j] + 1)
        return n - max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                boolean ok = true;
                for (String s : strs) {
                    if (s.charAt(j) > s.charAt(i)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
        }
        return n - Arrays.stream(f).max().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (ranges::all_of(strs, [&](const string& s) { return s[j] <= s[i]; })) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - ranges::max(f);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDeletionSize(strs []string) int {
	n := len(strs[0])
	f := make([]int, n)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			ok := true
			for _, s := range strs {
				if s[j] > s[i] {
					ok = false
					break
				}
			}
			if ok {
				f[i] = max(f[i], f[j]+1)
			}
		}
	}
	return n - slices.Max(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDeletionSize(strs: string[]): number {
    const n = strs[0].length;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            let ok = true;
            for (const s of strs) {
                if (s[j] > s[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                f[i] = Math.max(f[i], f[j] + 1);
            }
        }
    }
    return n - Math.max(...f);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs[0].len();
        let mut f = vec![1; n];

        for i in 1..n {
            for j in 0..i {
                if strs.iter().all(|s| s.as_bytes()[j] <= s.as_bytes()[i]) {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
        }

        (n - *f.iter().max().unwrap()) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定由<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;个小写字母字符串组成的数组<meta charset="UTF-8" />&nbsp;<code>strs</code>&nbsp;，其中每个字符串长度相等。</p>

<p>选取一个删除索引序列，对于<meta charset="UTF-8" />&nbsp;<code>strs</code>&nbsp;中的每个字符串，删除对应每个索引处的字符。</p>

<p>比如，有<meta charset="UTF-8" />&nbsp;<code>strs = ["abcdef","uvwxyz"]</code>&nbsp;，删除索引序列<meta charset="UTF-8" />&nbsp;<code>{0, 2, 3}</code>&nbsp;，删除后为<meta charset="UTF-8" />&nbsp;<code>["bef", "vyz"]</code>&nbsp;。</p>

<p>假设，我们选择了一组删除索引<meta charset="UTF-8" />&nbsp;<code>answer</code>&nbsp;，那么在执行删除操作之后，最终得到的数组的行中的 <strong>每个元素</strong> 都是按<strong>字典序</strong>排列的（即&nbsp;<code>(strs[0][0] &lt;= strs[0][1] &lt;= ... &lt;= strs[0][strs[0].length - 1])</code>&nbsp;和&nbsp;<code>(strs[1][0] &lt;= strs[1][1] &lt;= ... &lt;= strs[1][strs[1].length - 1])</code> ，依此类推）。</p>

<p>请返回<meta charset="UTF-8" /><em>&nbsp;<code>answer.length</code>&nbsp;的最小可能值</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["babca","bbazb"]
<strong>输出：</strong>3
<strong>解释：
</strong>删除 0、1 和 4 这三列后，最终得到的数组是 strs = ["bc", "az"]。
这两行是分别按字典序排列的（即，strs[0][0] &lt;= strs[0][1] 且 strs[1][0] &lt;= strs[1][1]）。
注意，strs[0] &gt; strs[1] —— 数组 strs 不一定是按字典序排列的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["edcba"]
<strong>输出：</strong>4
<strong>解释：</strong>如果删除的列少于 4 列，则剩下的行都不会按字典序排列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["ghi","def","abc"]
<strong>输出：</strong>0
<strong>解释：</strong>所有行都已按字典序排列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以第 $i$ 列结尾的最长不下降子序列的长度，初始时 $f[i] = 1$，答案即为 $n - \max(f)$。

考虑计算 $f[i]$，我们可以枚举 $j < i$，如果对于所有的字符串 $s$，有 $s[j] \le s[i]$，那么 $f[i] = \max(f[i], f[j] + 1)$。

最后，我们返回 $n - \max(f)$。

时间复杂度 $O(n^2 \times m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $\textit{strs}$ 每个字符串的长度和数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs[0])
        f = [1] * n
        for i in range(n):
            for j in range(i):
                if all(s[j] <= s[i] for s in strs):
                    f[i] = max(f[i], f[j] + 1)
        return n - max(f)
```

#### Java

```java
class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                boolean ok = true;
                for (String s : strs) {
                    if (s.charAt(j) > s.charAt(i)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
        }
        return n - Arrays.stream(f).max().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (ranges::all_of(strs, [&](const string& s) { return s[j] <= s[i]; })) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - ranges::max(f);
    }
};
```

#### Go

```go
func minDeletionSize(strs []string) int {
	n := len(strs[0])
	f := make([]int, n)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			ok := true
			for _, s := range strs {
				if s[j] > s[i] {
					ok = false
					break
				}
			}
			if ok {
				f[i] = max(f[i], f[j]+1)
			}
		}
	}
	return n - slices.Max(f)
}
```

#### TypeScript

```ts
function minDeletionSize(strs: string[]): number {
    const n = strs[0].length;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            let ok = true;
            for (const s of strs) {
                if (s[j] > s[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                f[i] = Math.max(f[i], f[j] + 1);
            }
        }
    }
    return n - Math.max(...f);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs[0].len();
        let mut f = vec![1; n];

        for i in 1..n {
            for j in 0..i {
                if strs.iter().all(|s| s.as_bytes()[j] <= s.as_bytes()[i]) {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
        }

        (n - *f.iter().max().unwrap()) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [961. 在长度 2N 的数组中找出重复 N 次的元素](https://leetcode.cn/problems/n-repeated-element-in-size-2n-array){#961}

{{< tabs "961" >}}

{{% tab "python" %}}
```python
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        s = set()
        for x in nums:
            if x in s:
                return x
            s.add(x)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> s = new HashSet<>(nums.length / 2 + 1);
        for (int i = 0;; ++i) {
            if (!s.add(nums[i])) {
                return nums[i];
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
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0;; ++i) {
            if (s.count(nums[i])) {
                return nums[i];
            }
            s.insert(nums[i]);
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatedNTimes(nums []int) int {
	s := map[int]bool{}
	for i := 0; ; i++ {
		if s[nums[i]] {
			return nums[i]
		}
		s[nums[i]] = true
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatedNTimes(nums: number[]): number {
    const s: Set<number> = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return x;
        }
        s.add(x);
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
var repeatedNTimes = function (nums) {
    const s = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return x;
        }
        s.add(x);
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，该数组具有以下属性：</p>

<div class="original__bRMd">
<div>
<ul>
	<li><code>nums.length == 2 * n</code>.</li>
	<li><code>nums</code> 包含 <code>n + 1</code> 个 <strong>不同的</strong> 元素</li>
	<li><code>nums</code> 中恰有一个元素重复 <code>n</code> 次</li>
</ul>

<p>找出并返回重复了 <code>n</code><em> </em>次的那个元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,3]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,2,5,3,2]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,5,2,5,3,5,4]
<strong>输出：</strong>5
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5000</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 由 <code>n + 1</code> 个<strong> 不同的</strong> 元素组成，且其中一个元素恰好重复 <code>n</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

由于数组 $nums$ 一共有 $2n$ 个元素，其中有 $n + 1$ 个不同的元素，且有一个元素重复了 $n$ 次，说明数组中的其余 $n$ 个元素都是不同的。

因此，我们只需要遍历数组 $nums$，用哈希表 $s$ 记录遍历过的元素。当遍历到某个元素 $x$ 时，如果 $x$ 在哈希表 $s$ 中已经存在，说明 $x$ 是重复的元素，直接返回 $x$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        s = set()
        for x in nums:
            if x in s:
                return x
            s.add(x)
```

#### Java

```java
class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> s = new HashSet<>(nums.length / 2 + 1);
        for (int i = 0;; ++i) {
            if (!s.add(nums[i])) {
                return nums[i];
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0;; ++i) {
            if (s.count(nums[i])) {
                return nums[i];
            }
            s.insert(nums[i]);
        }
    }
};
```

#### Go

```go
func repeatedNTimes(nums []int) int {
	s := map[int]bool{}
	for i := 0; ; i++ {
		if s[nums[i]] {
			return nums[i]
		}
		s[nums[i]] = true
	}
}
```

#### TypeScript

```ts
function repeatedNTimes(nums: number[]): number {
    const s: Set<number> = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return x;
        }
        s.add(x);
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var repeatedNTimes = function (nums) {
    const s = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return x;
        }
        s.add(x);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [962. 最大宽度坡](https://leetcode.cn/problems/maximum-width-ramp){#962}

{{< tabs "962" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stk = []
        for i, v in enumerate(nums):
            if not stk or nums[stk[-1]] > v:
                stk.append(i)
        ans = 0
        for i in range(len(nums) - 1, -1, -1):
            while stk and nums[stk[-1]] <= nums[i]:
                ans = max(ans, i - stk.pop())
            if not stk:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (stk.isEmpty() || nums[stk.peek()] > nums[i]) {
                stk.push(i);
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                ans = Math.max(ans, i - stk.pop());
            }
            if (stk.isEmpty()) {
                break;
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
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || nums[stk.top()] > nums[i]) stk.push(i);
        }
        int ans = 0;
        for (int i = n - 1; i; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                ans = max(ans, i - stk.top());
                stk.pop();
            }
            if (stk.empty()) break;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxWidthRamp(nums []int) int {
	n := len(nums)
	stk := []int{}
	for i, v := range nums {
		if len(stk) == 0 || nums[stk[len(stk)-1]] > v {
			stk = append(stk, i)
		}
	}
	ans := 0
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= nums[i] {
			ans = max(ans, i-stk[len(stk)-1])
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 {
			break
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxWidthRamp(nums: number[]): number {
    const idx = nums.map((x, i) => [x, i]).sort(([a], [b]) => a - b);
    let [ans, j] = [0, nums.length];

    for (const [_, i] of idx) {
        ans = Math.max(ans, i - j);
        j = Math.min(j, i);
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maxWidthRamp(nums) {
    const idx = nums.map((x, i) => [x, i]).sort(([a], [b]) => a - b);
    let [ans, j] = [0, nums.length];

    for (const [_, i] of idx) {
        ans = Math.max(ans, i - j);
        j = Math.min(j, i);
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

<p>给定一个整数数组&nbsp;<code>A</code>，<em>坡</em>是元组&nbsp;<code>(i, j)</code>，其中&nbsp;&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>A[i] &lt;= A[j]</code>。这样的坡的宽度为&nbsp;<code>j - i</code>。</p>

<p>找出&nbsp;<code>A</code>&nbsp;中的坡的最大宽度，如果不存在，返回 0 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[6,0,8,2,1,5]
<strong>输出：</strong>4
<strong>解释：</strong>
最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[9,8,1,0,1,9,4,0,4,1]
<strong>输出：</strong>7
<strong>解释：</strong>
最大宽度的坡为 (i, j) = (2, 9): A[2] = 1 且 A[9] = 1.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>2 &lt;= A.length &lt;= 50000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 50000</code></li>
</ol>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

根据题意，我们可以发现，所有可能的 $nums[i]$ 所构成的子序列一定是单调递减的。为什么呢？我们不妨用反证法证明一下。

假设存在 $i_1<i_2$，并且 $nums[i_1]<=nums[i_2]$，那么实际上 $nums[i_2]$一定不可能是一个候选值，因为 $nums[i_1]$ 更靠左，会是一个更优的值。因此 $nums[i]$ 所构成的子序列一定单调递减，并且 $i$ 一定是从 0 开始。

我们用一个从栈底到栈顶单调递减的栈 $stk$ 来存储所有可能的 $nums[i]$，然后我们从右边界开始遍历 $j$，若遇到 $nums[stk.top()]<=nums[j]$，说明此时构成一个坡，循环弹出栈顶元素，更新 ans。

时间复杂度 $O(n)$，其中 $n$ 表示 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stk = []
        for i, v in enumerate(nums):
            if not stk or nums[stk[-1]] > v:
                stk.append(i)
        ans = 0
        for i in range(len(nums) - 1, -1, -1):
            while stk and nums[stk[-1]] <= nums[i]:
                ans = max(ans, i - stk.pop())
            if not stk:
                break
        return ans
```

#### Java

```java
class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (stk.isEmpty() || nums[stk.peek()] > nums[i]) {
                stk.push(i);
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                ans = Math.max(ans, i - stk.pop());
            }
            if (stk.isEmpty()) {
                break;
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
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || nums[stk.top()] > nums[i]) stk.push(i);
        }
        int ans = 0;
        for (int i = n - 1; i; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                ans = max(ans, i - stk.top());
                stk.pop();
            }
            if (stk.empty()) break;
        }
        return ans;
    }
};
```

#### Go

```go
func maxWidthRamp(nums []int) int {
	n := len(nums)
	stk := []int{}
	for i, v := range nums {
		if len(stk) == 0 || nums[stk[len(stk)-1]] > v {
			stk = append(stk, i)
		}
	}
	ans := 0
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= nums[i] {
			ans = max(ans, i-stk[len(stk)-1])
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 {
			break
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxWidthRamp(nums: number[]): number {
    let [ans, n] = [0, nums.length];
    const stk: number[] = [];

    for (let i = 0; i < n - 1; i++) {
        if (stk.length === 0 || nums[stk.at(-1)!] > nums[i]) {
            stk.push(i);
        }
    }

    for (let i = n - 1; i >= 0; i--) {
        while (stk.length && nums[stk.at(-1)!] <= nums[i]) {
            ans = Math.max(ans, i - stk.pop()!);
        }
        if (stk.length === 0) break;
    }

    return ans;
}
```

#### JavaScript

```js
function maxWidthRamp(nums) {
    let [ans, n] = [0, nums.length];
    const stk = [];

    for (let i = 0; i < n - 1; i++) {
        if (stk.length === 0 || nums[stk.at(-1)] > nums[i]) {
            stk.push(i);
        }
    }

    for (let i = n - 1; i >= 0; i--) {
        while (stk.length && nums[stk.at(-1)] <= nums[i]) {
            ans = Math.max(ans, i - stk.pop());
        }
        if (stk.length === 0) break;
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序

<!-- tabs:start -->

#### TypeScript

```ts
function maxWidthRamp(nums: number[]): number {
    const idx = nums.map((x, i) => [x, i]).sort(([a], [b]) => a - b);
    let [ans, j] = [0, nums.length];

    for (const [_, i] of idx) {
        ans = Math.max(ans, i - j);
        j = Math.min(j, i);
    }

    return ans;
}
```

#### JavaScript

```js
function maxWidthRamp(nums) {
    const idx = nums.map((x, i) => [x, i]).sort(([a], [b]) => a - b);
    let [ans, j] = [0, nums.length];

    for (const [_, i] of idx) {
        ans = Math.max(ans, i - j);
        j = Math.min(j, i);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [963. 最小面积矩形 II](https://leetcode.cn/problems/minimum-area-rectangle-ii){#963}

{{< tabs "963" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        s = {(x, y) for x, y in points}
        n = len(points)
        ans = inf
        for i in range(n):
            x1, y1 = points[i]
            for j in range(n):
                if j != i:
                    x2, y2 = points[j]
                    for k in range(j + 1, n):
                        if k != i:
                            x3, y3 = points[k]
                            x4 = x2 - x1 + x3
                            y4 = y2 - y1 + y3
                            if (x4, y4) in s:
                                v21 = (x2 - x1, y2 - y1)
                                v31 = (x3 - x1, y3 - y1)
                                if v21[0] * v31[0] + v21[1] * v31[1] == 0:
                                    w = sqrt(v21[0] ** 2 + v21[1] ** 2)
                                    h = sqrt(v31[0] ** 2 + v31[1] ** 2)
                                    ans = min(ans, w * h)
        return 0 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double minAreaFreeRect(int[][] points) {
        int n = points.length;
        Set<Integer> s = new HashSet<>(n);
        for (int[] p : points) {
            s.add(f(p[0], p[1]));
        }
        double ans = Double.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    int x2 = points[j][0], y2 = points[j][1];
                    for (int k = j + 1; k < n; ++k) {
                        if (k != i) {
                            int x3 = points[k][0], y3 = points[k][1];
                            int x4 = x2 - x1 + x3, y4 = y2 - y1 + y3;
                            if (s.contains(f(x4, y4))) {
                                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                                    int ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                    int hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                    ans = Math.min(ans, Math.sqrt(1L * ww * hh));
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans == Double.MAX_VALUE ? 0 : ans;
    }

    private int f(int x, int y) {
        return x * 40001 + y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        auto f = [](int x, int y) {
            return x * 40001 + y;
        };
        int n = points.size();
        unordered_set<int> s;
        for (auto& p : points) {
            s.insert(f(p[0], p[1]));
        }
        double ans = 1e20;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    int x2 = points[j][0], y2 = points[j][1];
                    for (int k = j + 1; k < n; ++k) {
                        if (k != i) {
                            int x3 = points[k][0], y3 = points[k][1];
                            int x4 = x2 - x1 + x3, y4 = y2 - y1 + y3;
                            if (x4 >= 0 && x4 < 40000 && y4 >= 0 && y4 <= 40000 && s.count(f(x4, y4))) {
                                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                                    int ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                    int hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                    ans = min(ans, sqrt(1LL * ww * hh));
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans == 1e20 ? 0 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAreaFreeRect(points [][]int) float64 {
	n := len(points)
	f := func(x, y int) int {
		return x*40001 + y
	}
	s := map[int]bool{}
	for _, p := range points {
		s[f(p[0], p[1])] = true
	}
	ans := 1e20
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		for j := 0; j < n; j++ {
			if j != i {
				x2, y2 := points[j][0], points[j][1]
				for k := j + 1; k < n; k++ {
					if k != i {
						x3, y3 := points[k][0], points[k][1]
						x4, y4 := x2-x1+x3, y2-y1+y3
						if s[f(x4, y4)] {
							if (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1) == 0 {
								ww := (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
								hh := (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)
								ans = math.Min(ans, math.Sqrt(float64(ww*hh)))
							}
						}
					}
				}
			}
		}
	}
	if ans == 1e20 {
		return 0
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minAreaFreeRect(points: number[][]): number {
    const n = points.length;
    const f = (x: number, y: number): number => x * 40001 + y;
    const s: Set<number> = new Set();
    for (const [x, y] of points) {
        s.add(f(x, y));
    }
    let ans = Number.MAX_VALUE;
    for (let i = 0; i < n; ++i) {
        const [x1, y1] = points[i];
        for (let j = 0; j < n; ++j) {
            if (j !== i) {
                const [x2, y2] = points[j];
                for (let k = j + 1; k < n; ++k) {
                    if (k !== i) {
                        const [x3, y3] = points[k];
                        const x4 = x2 - x1 + x3;
                        const y4 = y2 - y1 + y3;
                        if (s.has(f(x4, y4))) {
                            if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) === 0) {
                                const ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                const hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                ans = Math.min(ans, Math.sqrt(ww * hh));
                            }
                        }
                    }
                }
            }
        }
    }
    return ans === Number.MAX_VALUE ? 0 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<strong>X-Y&nbsp;</strong>平面上的点数组 <code>points</code>，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>。</p>

<p>返回由这些点形成的任意矩形的最小面积，矩形的边&nbsp;<strong>不一定 </strong>平行于 X 轴和 Y 轴。如果不存在这样的矩形，则返回 <code>0</code>。</p>

<p>答案只需在<code>10<sup>-5</sup></code> 的误差范围内即可被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0963.Minimum%20Area%20Rectangle%20II/images/1a.png" style="width: 398px; height: 400px;" />
<pre>
<strong>输入：</strong> points = [[1,2],[2,1],[1,0],[0,1]]
<strong>输出：</strong> 2.00000
<strong>解释：</strong> 最小面积矩形由 [1,2]、[2,1]、[1,0]、[0,1] 组成，其面积为 2。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0963.Minimum%20Area%20Rectangle%20II/images/2.png" style="width: 400px; height: 251px;" />
<pre>
<strong>输入：</strong> points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
<strong>输出：</strong> 1.00000
<strong>解释：</strong> 最小面积矩形由 [1,0]、[1,1]、[2,1]、[2,0] 组成，其面积为 1。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0963.Minimum%20Area%20Rectangle%20II/images/3.png" style="width: 383px; height: 400px;" />
<pre>
<strong>输入：</strong> points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
<strong>输出：</strong> 0
<strong>解释：</strong> 无法由这些点组成任何矩形。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 50</code></li>
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

### 方法一：哈希表 + 枚举

我们用哈希表存放所有的点，然后枚举三个点 $p_1 = (x_1, y_1)$, $p_2 = (x_2, y_2)$, $p_3 = (x_3, y_3)$，其中 $p_2$ 和 $p_3$ 是矩形的对角线的两个端点。如果 $p_1$ 和 $p_2$ 构成的直线以及 $p_1$ 和 $p_3$ 构成的直线垂直，并且第四个点 $(x_4, y_4)=(x_2 - x_1 + x_3, y_2 - y_1 + y_3)$ 存在于哈希表中，那么就找到了一个矩形。此时，我们可以计算出矩形的面积，并更新答案。

最后，如果找到满足条件的矩形，返回其中面积的最小值。否则，返回 $0$。

时间复杂度 $O(n^3)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        s = {(x, y) for x, y in points}
        n = len(points)
        ans = inf
        for i in range(n):
            x1, y1 = points[i]
            for j in range(n):
                if j != i:
                    x2, y2 = points[j]
                    for k in range(j + 1, n):
                        if k != i:
                            x3, y3 = points[k]
                            x4 = x2 - x1 + x3
                            y4 = y2 - y1 + y3
                            if (x4, y4) in s:
                                v21 = (x2 - x1, y2 - y1)
                                v31 = (x3 - x1, y3 - y1)
                                if v21[0] * v31[0] + v21[1] * v31[1] == 0:
                                    w = sqrt(v21[0] ** 2 + v21[1] ** 2)
                                    h = sqrt(v31[0] ** 2 + v31[1] ** 2)
                                    ans = min(ans, w * h)
        return 0 if ans == inf else ans
```

#### Java

```java
class Solution {
    public double minAreaFreeRect(int[][] points) {
        int n = points.length;
        Set<Integer> s = new HashSet<>(n);
        for (int[] p : points) {
            s.add(f(p[0], p[1]));
        }
        double ans = Double.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    int x2 = points[j][0], y2 = points[j][1];
                    for (int k = j + 1; k < n; ++k) {
                        if (k != i) {
                            int x3 = points[k][0], y3 = points[k][1];
                            int x4 = x2 - x1 + x3, y4 = y2 - y1 + y3;
                            if (s.contains(f(x4, y4))) {
                                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                                    int ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                    int hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                    ans = Math.min(ans, Math.sqrt(1L * ww * hh));
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans == Double.MAX_VALUE ? 0 : ans;
    }

    private int f(int x, int y) {
        return x * 40001 + y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        auto f = [](int x, int y) {
            return x * 40001 + y;
        };
        int n = points.size();
        unordered_set<int> s;
        for (auto& p : points) {
            s.insert(f(p[0], p[1]));
        }
        double ans = 1e20;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    int x2 = points[j][0], y2 = points[j][1];
                    for (int k = j + 1; k < n; ++k) {
                        if (k != i) {
                            int x3 = points[k][0], y3 = points[k][1];
                            int x4 = x2 - x1 + x3, y4 = y2 - y1 + y3;
                            if (x4 >= 0 && x4 < 40000 && y4 >= 0 && y4 <= 40000 && s.count(f(x4, y4))) {
                                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                                    int ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                    int hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                    ans = min(ans, sqrt(1LL * ww * hh));
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans == 1e20 ? 0 : ans;
    }
};
```

#### Go

```go
func minAreaFreeRect(points [][]int) float64 {
	n := len(points)
	f := func(x, y int) int {
		return x*40001 + y
	}
	s := map[int]bool{}
	for _, p := range points {
		s[f(p[0], p[1])] = true
	}
	ans := 1e20
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		for j := 0; j < n; j++ {
			if j != i {
				x2, y2 := points[j][0], points[j][1]
				for k := j + 1; k < n; k++ {
					if k != i {
						x3, y3 := points[k][0], points[k][1]
						x4, y4 := x2-x1+x3, y2-y1+y3
						if s[f(x4, y4)] {
							if (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1) == 0 {
								ww := (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
								hh := (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)
								ans = math.Min(ans, math.Sqrt(float64(ww*hh)))
							}
						}
					}
				}
			}
		}
	}
	if ans == 1e20 {
		return 0
	}
	return ans
}
```

#### TypeScript

```ts
function minAreaFreeRect(points: number[][]): number {
    const n = points.length;
    const f = (x: number, y: number): number => x * 40001 + y;
    const s: Set<number> = new Set();
    for (const [x, y] of points) {
        s.add(f(x, y));
    }
    let ans = Number.MAX_VALUE;
    for (let i = 0; i < n; ++i) {
        const [x1, y1] = points[i];
        for (let j = 0; j < n; ++j) {
            if (j !== i) {
                const [x2, y2] = points[j];
                for (let k = j + 1; k < n; ++k) {
                    if (k !== i) {
                        const [x3, y3] = points[k];
                        const x4 = x2 - x1 + x3;
                        const y4 = y2 - y1 + y3;
                        if (s.has(f(x4, y4))) {
                            if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) === 0) {
                                const ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                const hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                ans = Math.min(ans, Math.sqrt(ww * hh));
                            }
                        }
                    }
                }
            }
        }
    }
    return ans === Number.MAX_VALUE ? 0 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [964. 表示数字的最少运算符](https://leetcode.cn/problems/least-operators-to-express-number){#964}

{{< tabs "964" >}}

{{% tab "python" %}}
```python
class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        @cache
        def dfs(v: int) -> int:
            if x >= v:
                return min(v * 2 - 1, 2 * (x - v))
            k = 2
            while x**k < v:
                k += 1
            if x**k - v < v:
                return min(k + dfs(x**k - v), k - 1 + dfs(v - x ** (k - 1)))
            return k - 1 + dfs(v - x ** (k - 1))

        return dfs(target)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int x;
    private Map<Integer, Integer> f = new HashMap<>();

    public int leastOpsExpressTarget(int x, int target) {
        this.x = x;
        return dfs(target);
    }

    private int dfs(int v) {
        if (x >= v) {
            return Math.min(v * 2 - 1, 2 * (x - v));
        }
        if (f.containsKey(v)) {
            return f.get(v);
        }
        int k = 2;
        long y = (long) x * x;
        while (y < v) {
            y *= x;
            ++k;
        }
        int ans = k - 1 + dfs(v - (int) (y / x));
        if (y - v < v) {
            ans = Math.min(ans, k + dfs((int) y - v));
        }
        f.put(v, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, int> f;
        function<int(int)> dfs = [&](int v) -> int {
            if (x >= v) {
                return min(v * 2 - 1, 2 * (x - v));
            }
            if (f.count(v)) {
                return f[v];
            }
            int k = 2;
            long long y = x * x;
            while (y < v) {
                y *= x;
                ++k;
            }
            int ans = k - 1 + dfs(v - y / x);
            if (y - v < v) {
                ans = min(ans, k + dfs(y - v));
            }
            f[v] = ans;
            return ans;
        };
        return dfs(target);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func leastOpsExpressTarget(x int, target int) int {
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(v int) int {
		if x > v {
			return min(v*2-1, 2*(x-v))
		}
		if val, ok := f[v]; ok {
			return val
		}
		k := 2
		y := x * x
		for y < v {
			y *= x
			k++
		}
		ans := k - 1 + dfs(v-y/x)
		if y-v < v {
			ans = min(ans, k+dfs(y-v))
		}
		f[v] = ans
		return ans
	}
	return dfs(target)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function leastOpsExpressTarget(x: number, target: number): number {
    const f: Map<number, number> = new Map();
    const dfs = (v: number): number => {
        if (x > v) {
            return Math.min(v * 2 - 1, 2 * (x - v));
        }
        if (f.has(v)) {
            return f.get(v)!;
        }
        let k = 2;
        let y = x * x;
        while (y < v) {
            y *= x;
            ++k;
        }
        let ans = k - 1 + dfs(v - Math.floor(y / x));
        if (y - v < v) {
            ans = Math.min(ans, k + dfs(y - v));
        }
        f.set(v, ans);
        return ans;
    };
    return dfs(target);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数 <code>x</code>，我们将会写出一个形如&nbsp;<code>x (op1) x (op2) x (op3) x ...</code>&nbsp;的表达式，其中每个运算符&nbsp;<code>op1</code>，<code>op2</code>，… 可以是加、减、乘、除（<code>+</code>，<code>-</code>，<code>*</code>，或是&nbsp;<code>/</code>）之一。例如，对于&nbsp;<code>x = 3</code>，我们可以写出表达式&nbsp;<code>3 * 3 / 3 + 3 - 3</code>，该式的值为 3 。</p>

<p>在写这样的表达式时，我们需要遵守下面的惯例：</p>

<ul>
	<li>除运算符（<code>/</code>）返回有理数。</li>
	<li>任何地方都没有括号。</li>
	<li>我们使用通常的操作顺序：乘法和除法发生在加法和减法之前。</li>
	<li>不允许使用一元否定运算符（<code>-</code>）。例如，“<code>x - x</code>” 是一个有效的表达式，因为它只使用减法，但是 “<code>-x + x</code>” 不是，因为它使用了否定运算符。&nbsp;</li>
</ul>

<p>我们希望编写一个能使表达式等于给定的目标值 <code>target</code> 且运算符最少的表达式。返回所用运算符的最少数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 3, target = 19
<strong>输出：</strong>5
<strong>解释：</strong>3 * 3 + 3 * 3 + 3 / 3 。表达式包含 5 个运算符。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 5, target = 501
<strong>输出：</strong>8
<strong>解释：</strong>5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5 。表达式包含 8 个运算符。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>x = 100, target = 100000000
<strong>输出：</strong>3
<strong>解释：</strong>100 * 100 * 100 * 100 。表达式包含 3 个运算符。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= x &lt;= 100</code></li>
	<li><code>1 &lt;= target &lt;= 2 * 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们定义一个函数 $dfs(v)$，表示用 $x$ 凑成数字 $v$ 所需要的最少运算符数量。那么答案就是 $dfs(target)$。

函数 $dfs(v)$ 的执行逻辑如下：

如果 $x \geq v$，那么此时可以用 $v$ 个 $x / x$ 相加来得到 $v$，运算符数量为 $v \times 2 - 1$；也可以用 $x$ 减去 $(x - v)$ 个 $x / x$ 来得到 $v$，运算符数量为 $(x - v) \times 2$。取两者的最小值。

否则，我们从 $k=2$ 开始枚举 $x^k$，找到第一个 $x^k \geq v$ 的 $k$：

-   如果此时 $x^k - v \geq v$，那么只能先得到 $x^{k-1}$，然后再递归计算 $dfs(v - x^{k-1})$，此时运算符数量为 $k - 1 + dfs(v - x^{k-1})$；
-   如果此时 $x^k - v < v$，那么可以按照上面的方式得到 $v$，此时运算符数量为 $k - 1 + dfs(v - x^{k-1})$；也可以先得到 $x^k$，再递归计算 $dfs(x^k - v)$，此时运算符数量为 $k + dfs(x^k - v)$。取两者的最小值。

为了避免重复计算，我们使用记忆化搜索的方式实现 $dfs$ 函数。

时间复杂度 $O(\log_{x}{target})$，空间复杂度 $O(\log_{x}{target})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        @cache
        def dfs(v: int) -> int:
            if x >= v:
                return min(v * 2 - 1, 2 * (x - v))
            k = 2
            while x**k < v:
                k += 1
            if x**k - v < v:
                return min(k + dfs(x**k - v), k - 1 + dfs(v - x ** (k - 1)))
            return k - 1 + dfs(v - x ** (k - 1))

        return dfs(target)
```

#### Java

```java
class Solution {
    private int x;
    private Map<Integer, Integer> f = new HashMap<>();

    public int leastOpsExpressTarget(int x, int target) {
        this.x = x;
        return dfs(target);
    }

    private int dfs(int v) {
        if (x >= v) {
            return Math.min(v * 2 - 1, 2 * (x - v));
        }
        if (f.containsKey(v)) {
            return f.get(v);
        }
        int k = 2;
        long y = (long) x * x;
        while (y < v) {
            y *= x;
            ++k;
        }
        int ans = k - 1 + dfs(v - (int) (y / x));
        if (y - v < v) {
            ans = Math.min(ans, k + dfs((int) y - v));
        }
        f.put(v, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, int> f;
        function<int(int)> dfs = [&](int v) -> int {
            if (x >= v) {
                return min(v * 2 - 1, 2 * (x - v));
            }
            if (f.count(v)) {
                return f[v];
            }
            int k = 2;
            long long y = x * x;
            while (y < v) {
                y *= x;
                ++k;
            }
            int ans = k - 1 + dfs(v - y / x);
            if (y - v < v) {
                ans = min(ans, k + dfs(y - v));
            }
            f[v] = ans;
            return ans;
        };
        return dfs(target);
    }
};
```

#### Go

```go
func leastOpsExpressTarget(x int, target int) int {
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(v int) int {
		if x > v {
			return min(v*2-1, 2*(x-v))
		}
		if val, ok := f[v]; ok {
			return val
		}
		k := 2
		y := x * x
		for y < v {
			y *= x
			k++
		}
		ans := k - 1 + dfs(v-y/x)
		if y-v < v {
			ans = min(ans, k+dfs(y-v))
		}
		f[v] = ans
		return ans
	}
	return dfs(target)
}
```

#### TypeScript

```ts
function leastOpsExpressTarget(x: number, target: number): number {
    const f: Map<number, number> = new Map();
    const dfs = (v: number): number => {
        if (x > v) {
            return Math.min(v * 2 - 1, 2 * (x - v));
        }
        if (f.has(v)) {
            return f.get(v)!;
        }
        let k = 2;
        let y = x * x;
        while (y < v) {
            y *= x;
            ++k;
        }
        let ans = k - 1 + dfs(v - Math.floor(y / x));
        if (y - v < v) {
            ans = Math.min(ans, k + dfs(y - v));
        }
        f.set(v, ans);
        return ans;
    };
    return dfs(target);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [965. 单值二叉树](https://leetcode.cn/problems/univalued-binary-tree){#965}

{{< tabs "965" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode]) -> bool:
            if root is None:
                return True
            return root.val == x and dfs(root.left) and dfs(root.right)

        x = root.val
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
    private int x;

    public boolean isUnivalTree(TreeNode root) {
        x = root.val;
        return dfs(root);
    }

    private boolean dfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        return root.val == x && dfs(root.left) && dfs(root.right);
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
    bool isUnivalTree(TreeNode* root) {
        int x = root->val;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
            if (!root) {
                return true;
            }
            return root->val == x && dfs(root->left) && dfs(root->right);
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
func isUnivalTree(root *TreeNode) bool {
	x := root.Val
	var dfs func(*TreeNode) bool
	dfs = func(root *TreeNode) bool {
		if root == nil {
			return true
		}
		return root.Val == x && dfs(root.Left) && dfs(root.Right)
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

function isUnivalTree(root: TreeNode | null): boolean {
    const x = root!.val;
    const dfs = (root: TreeNode | null): boolean => {
        if (!root) {
            return true;
        }
        return root.val === x && dfs(root.left) && dfs(root.right);
    };
    return dfs(root);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let x = root.as_ref().unwrap().borrow().val;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, x: i32) -> bool {
            if let Some(n) = node {
                let n = n.borrow();
                n.val == x && dfs(n.left.clone(), x) && dfs(n.right.clone(), x)
            } else {
                true
            }
        }

        dfs(root, x)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果二叉树每个节点都具有相同的值，那么该二叉树就是<em>单值</em>二叉树。</p>

<p>只有给定的树是单值二叉树时，才返回&nbsp;<code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0965.Univalued%20Binary%20Tree/images/screen-shot-2018-12-25-at-50104-pm.png" style="height: 159px; width: 200px;"></p>

<pre><strong>输入：</strong>[1,1,1,1,1,null,1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0965.Univalued%20Binary%20Tree/images/screen-shot-2018-12-25-at-50050-pm.png" style="height: 158px; width: 200px;"></p>

<pre><strong>输入：</strong>[2,2,2,5,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>给定树的节点数范围是&nbsp;<code>[1, 100]</code>。</li>
	<li>每个节点的值都是整数，范围为&nbsp;<code>[0, 99]</code>&nbsp;。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们记根节点的值为 $x$，然后设计一个函数 $\text{dfs}(\text{root})$，它表示当前节点的值是否等于 $x$，并且它的左右子树也是单值二叉树。

在函数 $\text{dfs}(\text{root})$ 中，如果当前节点为空，那么返回 $\text{true}$，否则，如果当前节点的值等于 $x$，并且它的左右子树也是单值二叉树，那么返回 $\text{true}$，否则返回 $\text{false}$。

在主函数中，我们调用 $\text{dfs}(\text{root})$，并返回结果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中的节点数目。

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
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode]) -> bool:
            if root is None:
                return True
            return root.val == x and dfs(root.left) and dfs(root.right)

        x = root.val
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
    private int x;

    public boolean isUnivalTree(TreeNode root) {
        x = root.val;
        return dfs(root);
    }

    private boolean dfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        return root.val == x && dfs(root.left) && dfs(root.right);
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
    bool isUnivalTree(TreeNode* root) {
        int x = root->val;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> bool {
            if (!root) {
                return true;
            }
            return root->val == x && dfs(root->left) && dfs(root->right);
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
func isUnivalTree(root *TreeNode) bool {
	x := root.Val
	var dfs func(*TreeNode) bool
	dfs = func(root *TreeNode) bool {
		if root == nil {
			return true
		}
		return root.Val == x && dfs(root.Left) && dfs(root.Right)
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

function isUnivalTree(root: TreeNode | null): boolean {
    const x = root!.val;
    const dfs = (root: TreeNode | null): boolean => {
        if (!root) {
            return true;
        }
        return root.val === x && dfs(root.left) && dfs(root.right);
    };
    return dfs(root);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let x = root.as_ref().unwrap().borrow().val;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, x: i32) -> bool {
            if let Some(n) = node {
                let n = n.borrow();
                n.val == x && dfs(n.left.clone(), x) && dfs(n.right.clone(), x)
            } else {
                true
            }
        }

        dfs(root, x)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [966. 元音拼写检查器](https://leetcode.cn/problems/vowel-spellchecker){#966}

{{< tabs "966" >}}

{{% tab "python" %}}
```python
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def f(w):
            t = []
            for c in w:
                t.append("*" if c in "aeiou" else c)
            return "".join(t)

        s = set(wordlist)
        low, pat = {}, {}
        for w in wordlist:
            t = w.lower()
            low.setdefault(t, w)
            pat.setdefault(f(t), w)

        ans = []
        for q in queries:
            if q in s:
                ans.append(q)
                continue
            q = q.lower()
            if q in low:
                ans.append(low[q])
                continue
            q = f(q)
            if q in pat:
                ans.append(pat[q])
                continue
            ans.append("")
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> s = new HashSet<>();
        Map<String, String> low = new HashMap<>();
        Map<String, String> pat = new HashMap<>();
        for (String w : wordlist) {
            s.add(w);
            String t = w.toLowerCase();
            low.putIfAbsent(t, w);
            pat.putIfAbsent(f(t), w);
        }
        int m = queries.length;
        String[] ans = new String[m];
        for (int i = 0; i < m; ++i) {
            String q = queries[i];
            if (s.contains(q)) {
                ans[i] = q;
                continue;
            }
            q = q.toLowerCase();
            if (low.containsKey(q)) {
                ans[i] = low.get(q);
                continue;
            }
            q = f(q);
            if (pat.containsKey(q)) {
                ans[i] = pat.get(q);
                continue;
            }
            ans[i] = "";
        }
        return ans;
    }

    private String f(String w) {
        char[] cs = w.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            char c = cs[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cs[i] = '*';
            }
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s(wordlist.begin(), wordlist.end());
        unordered_map<string, string> low;
        unordered_map<string, string> pat;
        auto f = [](string& w) {
            string res;
            for (char& c : w) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    res += '*';
                } else {
                    res += c;
                }
            }
            return res;
        };
        for (const auto& w : wordlist) {
            string t = w;
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            if (!low.contains(t)) {
                low[t] = w;
            }
            t = f(t);
            if (!pat.contains(t)) {
                pat[t] = w;
            }
        }
        vector<string> ans;
        for (auto& q : queries) {
            if (s.contains(q)) {
                ans.emplace_back(q);
                continue;
            }
            transform(q.begin(), q.end(), q.begin(), ::tolower);
            if (low.contains(q)) {
                ans.emplace_back(low[q]);
                continue;
            }
            q = f(q);
            if (pat.contains(q)) {
                ans.emplace_back(pat[q]);
                continue;
            }
            ans.emplace_back("");
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func spellchecker(wordlist []string, queries []string) (ans []string) {
	s := map[string]bool{}
	low := map[string]string{}
	pat := map[string]string{}
	f := func(w string) string {
		res := []byte(w)
		for i := range res {
			if res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u' {
				res[i] = '*'
			}
		}
		return string(res)
	}
	for _, w := range wordlist {
		s[w] = true
		t := strings.ToLower(w)
		if _, ok := low[t]; !ok {
			low[t] = w
		}
		if _, ok := pat[f(t)]; !ok {
			pat[f(t)] = w
		}
	}
	for _, q := range queries {
		if s[q] {
			ans = append(ans, q)
			continue
		}
		q = strings.ToLower(q)
		if s, ok := low[q]; ok {
			ans = append(ans, s)
			continue
		}
		q = f(q)
		if s, ok := pat[q]; ok {
			ans = append(ans, s)
			continue
		}
		ans = append(ans, "")
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function spellchecker(wordlist: string[], queries: string[]): string[] {
    const s = new Set(wordlist);
    const low = new Map<string, string>();
    const pat = new Map<string, string>();

    const f = (w: string): string => {
        let res = '';
        for (const c of w) {
            if ('aeiou'.includes(c)) {
                res += '*';
            } else {
                res += c;
            }
        }
        return res;
    };

    for (const w of wordlist) {
        let t = w.toLowerCase();
        if (!low.has(t)) {
            low.set(t, w);
        }
        t = f(t);
        if (!pat.has(t)) {
            pat.set(t, w);
        }
    }

    const ans: string[] = [];
    for (let q of queries) {
        if (s.has(q)) {
            ans.push(q);
            continue;
        }
        q = q.toLowerCase();
        if (low.has(q)) {
            ans.push(low.get(q)!);
            continue;
        }
        q = f(q);
        if (pat.has(q)) {
            ans.push(pat.get(q)!);
            continue;
        }
        ans.push('');
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, HashMap};

impl Solution {
    pub fn spellchecker(wordlist: Vec<String>, queries: Vec<String>) -> Vec<String> {
        let s: HashSet<String> = wordlist.iter().cloned().collect();
        let mut low: HashMap<String, String> = HashMap::new();
        let mut pat: HashMap<String, String> = HashMap::new();

        let f = |w: &str| -> String {
            w.chars()
                .map(|c| match c {
                    'a' | 'e' | 'i' | 'o' | 'u' => '*',
                    _ => c,
                })
                .collect()
        };

        for w in &wordlist {
            let mut t = w.to_lowercase();
            if !low.contains_key(&t) {
                low.insert(t.clone(), w.clone());
            }
            t = f(&t);
            if !pat.contains_key(&t) {
                pat.insert(t.clone(), w.clone());
            }
        }

        let mut ans: Vec<String> = Vec::new();
        for query in queries {
            if s.contains(&query) {
                ans.push(query);
                continue;
            }
            let mut q = query.to_lowercase();
            if let Some(v) = low.get(&q) {
                ans.push(v.clone());
                continue;
            }
            q = f(&q);
            if let Some(v) = pat.get(&q) {
                ans.push(v.clone());
                continue;
            }
            ans.push("".to_string());
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

<p>在给定单词列表&nbsp;<code>wordlist</code>&nbsp;的情况下，我们希望实现一个拼写检查器，将查询单词转换为正确的单词。</p>

<p>对于给定的查询单词&nbsp;<code>query</code>，拼写检查器将会处理两类拼写错误：</p>

<ul>
	<li>大小写：如果查询匹配单词列表中的某个单词（<strong>不区分大小写</strong>），则返回的正确单词与单词列表中的大小写相同。

    <ul>
    	<li>例如：<code>wordlist = ["yellow"]</code>, <code>query = "YellOw"</code>: <code>correct = "yellow"</code></li>
    	<li>例如：<code>wordlist = ["Yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "Yellow"</code></li>
    	<li>例如：<code>wordlist = ["yellow"]</code>, <code>query = "yellow"</code>: <code>correct = "yellow"</code></li>
    </ul>
    </li>
    <li>元音错误：如果在将查询单词中的元音 <code>('a', 'e', 'i', 'o', 'u')</code>&nbsp;&nbsp;分别替换为任何元音后，能与单词列表中的单词匹配（<strong>不区分大小写</strong>），则返回的正确单词与单词列表中的匹配项大小写相同。
    <ul>
    	<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yollow"</code>: <code>correct = "YellOw"</code></li>
    	<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yeellow"</code>: <code>correct = ""</code> （无匹配项）</li>
    	<li>例如：<code>wordlist = ["YellOw"]</code>, <code>query = "yllw"</code>: <code>correct = ""</code> （无匹配项）</li>
    </ul>
    </li>

</ul>

<p>此外，拼写检查器还按照以下优先级规则操作：</p>

<ul>
	<li>当查询完全匹配单词列表中的某个单词（<strong>区分大小写</strong>）时，应返回相同的单词。</li>
	<li>当查询匹配到大小写问题的单词时，您应该返回单词列表中的第一个这样的匹配项。</li>
	<li>当查询匹配到元音错误的单词时，您应该返回单词列表中的第一个这样的匹配项。</li>
	<li>如果该查询在单词列表中没有匹配项，则应返回空字符串。</li>
</ul>

<p>给出一些查询 <code>queries</code>，返回一个单词列表 <code>answer</code>，其中 <code>answer[i]</code> 是由查询 <code>query = queries[i]</code> 得到的正确单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
<strong>输出：</strong>["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>wordlist = ["yellow"], queries = ["YellOw"]
<b>输出：</b>["yellow"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length, queries.length &lt;= 5000</code></li>
	<li><code>1 &lt;= wordlist[i].length, queries[i].length &lt;= 7</code></li>
	<li><code>wordlist[i]</code>&nbsp;和&nbsp;<code>queries[i]</code>&nbsp;只包含英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们遍历 $\textit{wordlist}$，将单词按照大小写不敏感、元音不敏感的规则分别存入哈希表 $\textit{low}$ 和 $\textit{pat}$ 中，其中 $\textit{low}$ 的键为单词的小写形式，$\textit{pat}$ 的键为将单词的元音字母替换为 `*` 后的字符串，值为单词本身。用哈希表 $\textit{s}$ 存储 $\textit{wordlist}$ 中的单词。

遍历 $\textit{queries}$，对于每个单词 $\textit{q}$，如果 $\textit{q}$ 在 $\textit{s}$ 中，说明 $\textit{q}$ 在 $\textit{wordlist}$ 中，直接将 $\textit{q}$ 加入答案数组 $\textit{ans}$ 中。

否则，如果 $\textit{q}$ 的小写形式在 $\textit{low}$ 中，说明 $\textit{q}$ 在 $\textit{wordlist}$ 中，且大小写不敏感，将 $\textit{low}[q.\text{lower}()]$ 加入答案数组 $\textit{ans}$ 中。

否则，如果将 $\textit{q}$ 的元音字母替换为 `*` 后的字符串在 $\textit{pat}$ 中，说明 $\textit{q}$ 在 $\textit{wordlist}$ 中，且元音不敏感，将 $\textit{pat}[f(q)]$ 加入答案数组 $\textit{ans}$ 中。

否则，说明 $\textit{q}$ 在 $\textit{wordlist}$ 中，且大小写和元音都不敏感，将空字符串加入答案数组 $\textit{ans}$ 中。

最后返回答案数组 $\textit{ans}$ 即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为 $\textit{wordlist}$ 和 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def f(w):
            t = []
            for c in w:
                t.append("*" if c in "aeiou" else c)
            return "".join(t)

        s = set(wordlist)
        low, pat = {}, {}
        for w in wordlist:
            t = w.lower()
            low.setdefault(t, w)
            pat.setdefault(f(t), w)

        ans = []
        for q in queries:
            if q in s:
                ans.append(q)
                continue
            q = q.lower()
            if q in low:
                ans.append(low[q])
                continue
            q = f(q)
            if q in pat:
                ans.append(pat[q])
                continue
            ans.append("")
        return ans
```

#### Java

```java
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> s = new HashSet<>();
        Map<String, String> low = new HashMap<>();
        Map<String, String> pat = new HashMap<>();
        for (String w : wordlist) {
            s.add(w);
            String t = w.toLowerCase();
            low.putIfAbsent(t, w);
            pat.putIfAbsent(f(t), w);
        }
        int m = queries.length;
        String[] ans = new String[m];
        for (int i = 0; i < m; ++i) {
            String q = queries[i];
            if (s.contains(q)) {
                ans[i] = q;
                continue;
            }
            q = q.toLowerCase();
            if (low.containsKey(q)) {
                ans[i] = low.get(q);
                continue;
            }
            q = f(q);
            if (pat.containsKey(q)) {
                ans[i] = pat.get(q);
                continue;
            }
            ans[i] = "";
        }
        return ans;
    }

    private String f(String w) {
        char[] cs = w.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            char c = cs[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cs[i] = '*';
            }
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s(wordlist.begin(), wordlist.end());
        unordered_map<string, string> low;
        unordered_map<string, string> pat;
        auto f = [](string& w) {
            string res;
            for (char& c : w) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    res += '*';
                } else {
                    res += c;
                }
            }
            return res;
        };
        for (const auto& w : wordlist) {
            string t = w;
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            if (!low.contains(t)) {
                low[t] = w;
            }
            t = f(t);
            if (!pat.contains(t)) {
                pat[t] = w;
            }
        }
        vector<string> ans;
        for (auto& q : queries) {
            if (s.contains(q)) {
                ans.emplace_back(q);
                continue;
            }
            transform(q.begin(), q.end(), q.begin(), ::tolower);
            if (low.contains(q)) {
                ans.emplace_back(low[q]);
                continue;
            }
            q = f(q);
            if (pat.contains(q)) {
                ans.emplace_back(pat[q]);
                continue;
            }
            ans.emplace_back("");
        }
        return ans;
    }
};
```

#### Go

```go
func spellchecker(wordlist []string, queries []string) (ans []string) {
	s := map[string]bool{}
	low := map[string]string{}
	pat := map[string]string{}
	f := func(w string) string {
		res := []byte(w)
		for i := range res {
			if res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u' {
				res[i] = '*'
			}
		}
		return string(res)
	}
	for _, w := range wordlist {
		s[w] = true
		t := strings.ToLower(w)
		if _, ok := low[t]; !ok {
			low[t] = w
		}
		if _, ok := pat[f(t)]; !ok {
			pat[f(t)] = w
		}
	}
	for _, q := range queries {
		if s[q] {
			ans = append(ans, q)
			continue
		}
		q = strings.ToLower(q)
		if s, ok := low[q]; ok {
			ans = append(ans, s)
			continue
		}
		q = f(q)
		if s, ok := pat[q]; ok {
			ans = append(ans, s)
			continue
		}
		ans = append(ans, "")
	}
	return
}
```

#### TypeScript

```ts
function spellchecker(wordlist: string[], queries: string[]): string[] {
    const s = new Set(wordlist);
    const low = new Map<string, string>();
    const pat = new Map<string, string>();

    const f = (w: string): string => {
        let res = '';
        for (const c of w) {
            if ('aeiou'.includes(c)) {
                res += '*';
            } else {
                res += c;
            }
        }
        return res;
    };

    for (const w of wordlist) {
        let t = w.toLowerCase();
        if (!low.has(t)) {
            low.set(t, w);
        }
        t = f(t);
        if (!pat.has(t)) {
            pat.set(t, w);
        }
    }

    const ans: string[] = [];
    for (let q of queries) {
        if (s.has(q)) {
            ans.push(q);
            continue;
        }
        q = q.toLowerCase();
        if (low.has(q)) {
            ans.push(low.get(q)!);
            continue;
        }
        q = f(q);
        if (pat.has(q)) {
            ans.push(pat.get(q)!);
            continue;
        }
        ans.push('');
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::{HashSet, HashMap};

impl Solution {
    pub fn spellchecker(wordlist: Vec<String>, queries: Vec<String>) -> Vec<String> {
        let s: HashSet<String> = wordlist.iter().cloned().collect();
        let mut low: HashMap<String, String> = HashMap::new();
        let mut pat: HashMap<String, String> = HashMap::new();

        let f = |w: &str| -> String {
            w.chars()
                .map(|c| match c {
                    'a' | 'e' | 'i' | 'o' | 'u' => '*',
                    _ => c,
                })
                .collect()
        };

        for w in &wordlist {
            let mut t = w.to_lowercase();
            if !low.contains_key(&t) {
                low.insert(t.clone(), w.clone());
            }
            t = f(&t);
            if !pat.contains_key(&t) {
                pat.insert(t.clone(), w.clone());
            }
        }

        let mut ans: Vec<String> = Vec::new();
        for query in queries {
            if s.contains(&query) {
                ans.push(query);
                continue;
            }
            let mut q = query.to_lowercase();
            if let Some(v) = low.get(&q) {
                ans.push(v.clone());
                continue;
            }
            q = f(&q);
            if let Some(v) = pat.get(&q) {
                ans.push(v.clone());
                continue;
            }
            ans.push("".to_string());
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

# [967. 连续差相同的数字](https://leetcode.cn/problems/numbers-with-same-consecutive-differences){#967}

{{< tabs "967" >}}

{{% tab "python" %}}
```python
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        def dfs(x: int):
            if x >= boundary:
                ans.append(x)
                return
            last = x % 10
            if last + k <= 9:
                dfs(x * 10 + last + k)
            if last - k >= 0 and k != 0:
                dfs(x * 10 + last - k)

        ans = []
        boundary = 10 ** (n - 1)
        for i in range(1, 10):
            dfs(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer> ans = new ArrayList<>();
    private int boundary;
    private int k;

    public int[] numsSameConsecDiff(int n, int k) {
        this.k = k;
        boundary = (int) Math.pow(10, n - 1);
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }

    private void dfs(int x) {
        if (x >= boundary) {
            ans.add(x);
            return;
        }
        int last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k != 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        int boundary = pow(10, n - 1);
        auto dfs = [&](this auto&& dfs, int x) {
            if (x >= boundary) {
                ans.push_back(x);
                return;
            }
            int last = x % 10;
            if (last + k < 10) {
                dfs(x * 10 + last + k);
            }
            if (k != 0 && last - k >= 0) {
                dfs(x * 10 + last - k);
            }
        };
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numsSameConsecDiff(n int, k int) (ans []int) {
	bounary := int(math.Pow10(n - 1))
	var dfs func(int)
	dfs = func(x int) {
		if x >= bounary {
			ans = append(ans, x)
			return
		}
		last := x % 10
		if last+k < 10 {
			dfs(x*10 + last + k)
		}
		if k > 0 && last-k >= 0 {
			dfs(x*10 + last - k)
		}
	}
	for i := 1; i < 10; i++ {
		dfs(i)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numsSameConsecDiff(n: number, k: number): number[] {
    const ans: number[] = [];
    const boundary = 10 ** (n - 1);
    const dfs = (x: number) => {
        if (x >= boundary) {
            ans.push(x);
            return;
        }
        const last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k > 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    };
    for (let i = 1; i < 10; i++) {
        dfs(i);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function (n, k) {
    const ans = [];
    const boundary = 10 ** (n - 1);
    const dfs = x => {
        if (x >= boundary) {
            ans.push(x);
            return;
        }
        const last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k > 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    };
    for (let i = 1; i < 10; i++) {
        dfs(i);
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

<p>返回所有长度为 <code>n</code> 且满足其每两个连续位上的数字之间的差的绝对值为 <code>k</code> 的<strong> 非负整数 </strong>。</p>

<p>请注意，<strong>除了 </strong>数字 <code>0</code> 本身之外，答案中的每个数字都 <strong>不能 </strong>有前导零。例如，<code>01</code> 有一个前导零，所以是无效的；但 <code>0</code>&nbsp;是有效的。</p>

<p>你可以按 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 7
<strong>输出：</strong>[181,292,707,818,929]
<strong>解释：</strong>注意，070 不是一个有效的数字，因为它有前导零。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 1
<strong>输出：</strong>[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 0
<strong>输出：</strong>[11,22,33,44,55,66,77,88,99]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 2
<strong>输出：</strong>[13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 9</code></li>
	<li><code>0 &lt;= k &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以枚举所有长度为 $n$ 的数字的第一个数字，然后使用深度优先搜索的方法，递归地构造所有符合条件的数字。

具体地，我们首先定义一个边界值 $\textit{boundary} = 10^{n-1}$，表示我们需要构造的数字的最小值。然后，我们从 $1$ 到 $9$ 枚举第一个数字，对于每一个数字 $i$，我们递归地构造以 $i$ 为第一个数字的长度为 $n$ 的数字。

时间复杂度 $(n \times 2^n \times |\Sigma|)$，其中 $|\Sigma|$ 表示数字集合，本题中 $|\Sigma| = 9$。空间复杂度 $O(2^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        def dfs(x: int):
            if x >= boundary:
                ans.append(x)
                return
            last = x % 10
            if last + k <= 9:
                dfs(x * 10 + last + k)
            if last - k >= 0 and k != 0:
                dfs(x * 10 + last - k)

        ans = []
        boundary = 10 ** (n - 1)
        for i in range(1, 10):
            dfs(i)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer> ans = new ArrayList<>();
    private int boundary;
    private int k;

    public int[] numsSameConsecDiff(int n, int k) {
        this.k = k;
        boundary = (int) Math.pow(10, n - 1);
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }

    private void dfs(int x) {
        if (x >= boundary) {
            ans.add(x);
            return;
        }
        int last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k != 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        int boundary = pow(10, n - 1);
        auto dfs = [&](this auto&& dfs, int x) {
            if (x >= boundary) {
                ans.push_back(x);
                return;
            }
            int last = x % 10;
            if (last + k < 10) {
                dfs(x * 10 + last + k);
            }
            if (k != 0 && last - k >= 0) {
                dfs(x * 10 + last - k);
            }
        };
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        return ans;
    }
};
```

#### Go

```go
func numsSameConsecDiff(n int, k int) (ans []int) {
	bounary := int(math.Pow10(n - 1))
	var dfs func(int)
	dfs = func(x int) {
		if x >= bounary {
			ans = append(ans, x)
			return
		}
		last := x % 10
		if last+k < 10 {
			dfs(x*10 + last + k)
		}
		if k > 0 && last-k >= 0 {
			dfs(x*10 + last - k)
		}
	}
	for i := 1; i < 10; i++ {
		dfs(i)
	}
	return
}
```

#### TypeScript

```ts
function numsSameConsecDiff(n: number, k: number): number[] {
    const ans: number[] = [];
    const boundary = 10 ** (n - 1);
    const dfs = (x: number) => {
        if (x >= boundary) {
            ans.push(x);
            return;
        }
        const last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k > 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    };
    for (let i = 1; i < 10; i++) {
        dfs(i);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function (n, k) {
    const ans = [];
    const boundary = 10 ** (n - 1);
    const dfs = x => {
        if (x >= boundary) {
            ans.push(x);
            return;
        }
        const last = x % 10;
        if (last + k < 10) {
            dfs(x * 10 + last + k);
        }
        if (k > 0 && last - k >= 0) {
            dfs(x * 10 + last - k);
        }
    };
    for (let i = 1; i < 10; i++) {
        dfs(i);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [968. 监控二叉树](https://leetcode.cn/problems/binary-tree-cameras){#968}

{{< tabs "968" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return inf, 0, 0
            la, lb, lc = dfs(root.left)
            ra, rb, rc = dfs(root.right)
            a = min(la, lb, lc) + min(ra, rb, rc) + 1
            b = min(la + rb, lb + ra, la + ra)
            c = lb + rb
            return a, b, c

        a, b, _ = dfs(root)
        return min(a, b)
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
    public int minCameraCover(TreeNode root) {
        int[] ans = dfs(root);
        return Math.min(ans[0], ans[1]);
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1 << 29, 0, 0};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int a = 1 + Math.min(Math.min(l[0], l[1]), l[2]) + Math.min(Math.min(r[0], r[1]), r[2]);
        int b = Math.min(Math.min(l[0] + r[1], l[1] + r[0]), l[0] + r[0]);
        int c = l[1] + r[1];
        return new int[] {a, b, c};
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
struct Status {
    int a, b, c;
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto [a, b, _] = dfs(root);
        return min(a, b);
    }

    Status dfs(TreeNode* root) {
        if (!root) {
            return {1 << 29, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = 1 + min({la, lb, lc}) + min({ra, rb, rc});
        int b = min({la + ra, la + rb, lb + ra});
        int c = lb + rb;
        return {a, b, c};
    };
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
func minCameraCover(root *TreeNode) int {
	var dfs func(*TreeNode) (int, int, int)
	dfs = func(root *TreeNode) (int, int, int) {
		if root == nil {
			return 1 << 29, 0, 0
		}
		la, lb, lc := dfs(root.Left)
		ra, rb, rc := dfs(root.Right)
		a := 1 + min(la, min(lb, lc)) + min(ra, min(rb, rc))
		b := min(la+ra, min(la+rb, lb+ra))
		c := lb + rb
		return a, b, c
	}
	a, b, _ := dfs(root)
	return min(a, b)
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

function minCameraCover(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null): number[] => {
        if (!root) {
            return [1 << 29, 0, 0];
        }
        const [la, lb, lc] = dfs(root.left);
        const [ra, rb, rc] = dfs(root.right);
        const a = 1 + Math.min(la, lb, lc) + Math.min(ra, rb, rc);
        const b = Math.min(la + ra, la + rb, lb + ra);
        const c = lb + rb;
        return [a, b, c];
    };
    const [a, b, _] = dfs(root);
    return Math.min(a, b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树，我们在树的节点上安装摄像头。</p>

<p>节点上的每个摄影头都可以监视<strong>其父对象、自身及其直接子对象。</strong></p>

<p>计算监控树的所有节点所需的最小摄像头数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0968.Binary%20Tree%20Cameras/images/bst_cameras_01.png" style="height: 163px; width: 138px;"></p>

<pre><strong>输入：</strong>[0,0,null,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>如图所示，一台摄像头足以监控所有节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0968.Binary%20Tree%20Cameras/images/bst_cameras_02.png" style="height: 312px; width: 139px;"></p>

<pre><strong>输入：</strong>[0,0,null,0,null,0,null,null,0]
<strong>输出：</strong>2
<strong>解释：</strong>需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
</pre>

<p><br>
<strong>提示：</strong></p>

<ol>
	<li>给定树的节点数的范围是&nbsp;<code>[1, 1000]</code>。</li>
	<li>每个节点的值都是 0。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（树形 DP）

对于每个节点，我们定义三种状态：

-   `a`：当前节点有摄像头
-   `b`：当前节点无摄像头，但被子节点监控
-   `c`：当前节点无摄像头，也没被子节点监控

接下来，我们设计一个函数 $dfs(root)$，它将返回一个长度为 3 的数组，表示以 `root` 为根的子树中，三种状态下的最小摄像头数量。那么答案就是 $\min(dfs(root)[0], dfs(root)[1])$。

函数 $dfs(root)$ 的计算过程如下：

如果 `root` 为空，则返回 $[inf, 0, 0]$，其中 `inf` 表示一个很大的数，它用于表示不可能的情况。

否则，我们递归计算 `root` 的左右子树，分别得到 $[la, lb, lc]$ 和 $[ra, rb, rc]$。

-   如果当前节点有摄像头，那么它的左右节点必须都是被监控的状态，即 $a = \min(la, lb, lc) + \min(ra, rb, rc) + 1$。
-   如果当前节点无摄像头，但被子节点监控，那么子节点可以是其中之一或者两个都有摄像头，即 $b = \min(la + rb, lb + ra, la + ra)$。
-   如果当前节点无摄像头，也没被子节点监控，那么子节点必须被其子节点监控，即 $c = lb + rb$。

最后，我们返回 $[a, b, c]$。

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
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return inf, 0, 0
            la, lb, lc = dfs(root.left)
            ra, rb, rc = dfs(root.right)
            a = min(la, lb, lc) + min(ra, rb, rc) + 1
            b = min(la + rb, lb + ra, la + ra)
            c = lb + rb
            return a, b, c

        a, b, _ = dfs(root)
        return min(a, b)
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
    public int minCameraCover(TreeNode root) {
        int[] ans = dfs(root);
        return Math.min(ans[0], ans[1]);
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1 << 29, 0, 0};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int a = 1 + Math.min(Math.min(l[0], l[1]), l[2]) + Math.min(Math.min(r[0], r[1]), r[2]);
        int b = Math.min(Math.min(l[0] + r[1], l[1] + r[0]), l[0] + r[0]);
        int c = l[1] + r[1];
        return new int[] {a, b, c};
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
struct Status {
    int a, b, c;
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto [a, b, _] = dfs(root);
        return min(a, b);
    }

    Status dfs(TreeNode* root) {
        if (!root) {
            return {1 << 29, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = 1 + min({la, lb, lc}) + min({ra, rb, rc});
        int b = min({la + ra, la + rb, lb + ra});
        int c = lb + rb;
        return {a, b, c};
    };
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
func minCameraCover(root *TreeNode) int {
	var dfs func(*TreeNode) (int, int, int)
	dfs = func(root *TreeNode) (int, int, int) {
		if root == nil {
			return 1 << 29, 0, 0
		}
		la, lb, lc := dfs(root.Left)
		ra, rb, rc := dfs(root.Right)
		a := 1 + min(la, min(lb, lc)) + min(ra, min(rb, rc))
		b := min(la+ra, min(la+rb, lb+ra))
		c := lb + rb
		return a, b, c
	}
	a, b, _ := dfs(root)
	return min(a, b)
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

function minCameraCover(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null): number[] => {
        if (!root) {
            return [1 << 29, 0, 0];
        }
        const [la, lb, lc] = dfs(root.left);
        const [ra, rb, rc] = dfs(root.right);
        const a = 1 + Math.min(la, lb, lc) + Math.min(ra, rb, rc);
        const b = Math.min(la + ra, la + rb, lb + ra);
        const c = lb + rb;
        return [a, b, c];
    };
    const [a, b, _] = dfs(root);
    return Math.min(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [969. 煎饼排序](https://leetcode.cn/problems/pancake-sorting){#969}

{{< tabs "969" >}}

{{% tab "python" %}}
```python
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def reverse(arr, j):
            i = 0
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i, j = i + 1, j - 1

        n = len(arr)
        ans = []
        for i in range(n - 1, 0, -1):
            j = i
            while j > 0 and arr[j] != i + 1:
                j -= 1
            if j < i:
                if j > 0:
                    ans.append(j + 1)
                    reverse(arr, j)
                ans.append(i + 1)
                reverse(arr, i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = n - 1; i > 0; --i) {
            int j = i;
            for (; j > 0 && arr[j] != i + 1; --j)
                ;
            if (j < i) {
                if (j > 0) {
                    ans.add(j + 1);
                    reverse(arr, j);
                }
                ans.add(i + 1);
                reverse(arr, i);
            }
        }
        return ans;
    }

    private void reverse(int[] arr, int j) {
        for (int i = 0; i < j; ++i, --j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = n - 1; i > 0; --i) {
            int j = i;
            for (; j > 0 && arr[j] != i + 1; --j)
                ;
            if (j == i) continue;
            if (j > 0) {
                ans.push_back(j + 1);
                reverse(arr.begin(), arr.begin() + j + 1);
            }
            ans.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + i + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pancakeSort(arr []int) []int {
	var ans []int
	n := len(arr)
	reverse := func(j int) {
		for i := 0; i < j; i, j = i+1, j-1 {
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	for i := n - 1; i > 0; i-- {
		j := i
		for ; j > 0 && arr[j] != i+1; j-- {
		}
		if j < i {
			if j > 0 {
				ans = append(ans, j+1)
				reverse(j)
			}
			ans = append(ans, i+1)
			reverse(i)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pancakeSort(arr: number[]): number[] {
    let ans = [];
    for (let n = arr.length; n > 1; n--) {
        let index = 0;
        for (let i = 1; i < n; i++) {
            if (arr[i] >= arr[index]) {
                index = i;
            }
        }
        if (index == n - 1) continue;
        reverse(arr, index);
        reverse(arr, n - 1);
        ans.push(index + 1);
        ans.push(n);
    }
    return ans;
}

function reverse(nums: Array<number>, end: number): void {
    for (let i = 0, j = end; i < j; i++, j--) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn pancake_sort(mut arr: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        for n in (1..arr.len()).rev() {
            let mut max_idx = 0;
            for idx in 0..=n {
                if arr[max_idx] < arr[idx] {
                    max_idx = idx;
                }
            }
            if max_idx != n {
                if max_idx != 0 {
                    arr[..=max_idx].reverse();
                    res.push((max_idx as i32) + 1);
                }
                arr[..=n].reverse();
                res.push((n as i32) + 1);
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> ，请使用 <strong>煎饼翻转</strong><em> </em>完成对数组的排序。</p>

<p>一次煎饼翻转的执行过程如下：</p>

<ul>
	<li>选择一个整数 <code>k</code> ，<code>1 <= k <= arr.length</code></li>
	<li>反转子数组 <code>arr[0...k-1]</code>（<strong>下标从 0 开始</strong>）</li>
</ul>

<p>例如，<code>arr = [3,2,1,4]</code> ，选择 <code>k = 3</code> 进行一次煎饼翻转，反转子数组 <code>[3,2,1]</code> ，得到 <code>arr = [<strong>1</strong>,<strong>2</strong>,<strong>3</strong>,4]</code> 。</p>

<p>以数组形式返回能使 <code>arr</code> 有序的煎饼翻转操作所对应的 <code>k</code> 值序列。任何将数组排序且翻转次数在 <code>10 * arr.length</code> 范围内的有效答案都将被判断为正确。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[3,2,4,1]
<strong>输出：</strong>[4,2,4,3]
<strong>解释：</strong>
我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
初始状态 arr = [3, 2, 4, 1]
第一次翻转后（k = 4）：arr = [<strong>1</strong>, <strong>4</strong>, <strong>2</strong>, <strong>3</strong>]
第二次翻转后（k = 2）：arr = [<strong>4</strong>, <strong>1</strong>, 2, 3]
第三次翻转后（k = 4）：arr = [<strong>3</strong>, <strong>2</strong>, <strong>1</strong>, <strong>4</strong>]
第四次翻转后（k = 3）：arr = [<strong>1</strong>, <strong>2</strong>, <strong>3</strong>, 4]，此时已完成排序。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3]
<strong>输出：</strong>[]
<strong>解释：
</strong>输入已经排序，因此不需要翻转任何内容。
请注意，其他可能的答案，如 [3，3] ，也将被判断为正确。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 100</code></li>
	<li><code>1 <= arr[i] <= arr.length</code></li>
	<li><code>arr</code> 中的所有整数互不相同（即，<code>arr</code> 是从 <code>1</code> 到 <code>arr.length</code> 整数的一个排列）</li>
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
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def reverse(arr, j):
            i = 0
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i, j = i + 1, j - 1

        n = len(arr)
        ans = []
        for i in range(n - 1, 0, -1):
            j = i
            while j > 0 and arr[j] != i + 1:
                j -= 1
            if j < i:
                if j > 0:
                    ans.append(j + 1)
                    reverse(arr, j)
                ans.append(i + 1)
                reverse(arr, i)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = n - 1; i > 0; --i) {
            int j = i;
            for (; j > 0 && arr[j] != i + 1; --j)
                ;
            if (j < i) {
                if (j > 0) {
                    ans.add(j + 1);
                    reverse(arr, j);
                }
                ans.add(i + 1);
                reverse(arr, i);
            }
        }
        return ans;
    }

    private void reverse(int[] arr, int j) {
        for (int i = 0; i < j; ++i, --j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = n - 1; i > 0; --i) {
            int j = i;
            for (; j > 0 && arr[j] != i + 1; --j)
                ;
            if (j == i) continue;
            if (j > 0) {
                ans.push_back(j + 1);
                reverse(arr.begin(), arr.begin() + j + 1);
            }
            ans.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func pancakeSort(arr []int) []int {
	var ans []int
	n := len(arr)
	reverse := func(j int) {
		for i := 0; i < j; i, j = i+1, j-1 {
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	for i := n - 1; i > 0; i-- {
		j := i
		for ; j > 0 && arr[j] != i+1; j-- {
		}
		if j < i {
			if j > 0 {
				ans = append(ans, j+1)
				reverse(j)
			}
			ans = append(ans, i+1)
			reverse(i)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function pancakeSort(arr: number[]): number[] {
    let ans = [];
    for (let n = arr.length; n > 1; n--) {
        let index = 0;
        for (let i = 1; i < n; i++) {
            if (arr[i] >= arr[index]) {
                index = i;
            }
        }
        if (index == n - 1) continue;
        reverse(arr, index);
        reverse(arr, n - 1);
        ans.push(index + 1);
        ans.push(n);
    }
    return ans;
}

function reverse(nums: Array<number>, end: number): void {
    for (let i = 0, j = end; i < j; i++, j--) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn pancake_sort(mut arr: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        for n in (1..arr.len()).rev() {
            let mut max_idx = 0;
            for idx in 0..=n {
                if arr[max_idx] < arr[idx] {
                    max_idx = idx;
                }
            }
            if max_idx != n {
                if max_idx != 0 {
                    arr[..=max_idx].reverse();
                    res.push((max_idx as i32) + 1);
                }
                arr[..=n].reverse();
                res.push((n as i32) + 1);
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
