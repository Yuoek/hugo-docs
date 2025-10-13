---
title: "0031_下一个排列"
date: 2025-10-08T18:34:13+08:00
weight: 4
tags: [二分查找, 动态规划, 双指针, 哈希表, 回溯, 字符串, 数组, 栈, 矩阵]
---

{{< markmap >}}
### [0031_下一个排列](#31)
#### [数组](#31)
#### [双指针](#31)
### [0032_最长有效括号](#32)
#### [栈](#32)
#### [字符串](#32)
#### [动态规划](#32)
### [0033_搜索旋转排序数组](#33)
#### [数组](#33)
#### [二分查找](#33)
### [0034_在排序数组中查找元素的第一个和最后一个位置](#34)
#### [数组](#34)
#### [二分查找](#34)
### [0035_搜索插入位置](#35)
#### [数组](#35)
#### [二分查找](#35)
### [0036_有效的数独](#36)
#### [数组](#36)
#### [哈希表](#36)
#### [矩阵](#36)
### [0037_解数独](#37)
#### [数组](#37)
#### [哈希表](#37)
#### [回溯](#37)
#### [矩阵](#37)
### [0038_外观数列](#38)
#### [字符串](#38)
### [0039_组合总和](#39)
#### [数组](#39)
#### [回溯](#39)
### [0040_组合总和 II](#40)
#### [数组](#40)
#### [回溯](#40)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0031_下一个排列
___
#### 数组
___
#### 双指针
---
### 0032_最长有效括号
___
#### 栈
___
#### 字符串
___
#### 动态规划
---
### 0033_搜索旋转排序数组
___
#### 数组
___
#### 二分查找
---
### 0034_在排序数组中查找元素的第一个和最后一个位置
___
#### 数组
___
#### 二分查找
---
### 0035_搜索插入位置
___
#### 数组
___
#### 二分查找
---
### 0036_有效的数独
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 0037_解数独
___
#### 数组
___
#### 哈希表
___
#### 回溯
___
#### 矩阵
---
### 0038_外观数列
___
#### 字符串
---
### 0039_组合总和
___
#### 数组
___
#### 回溯
---
### 0040_组合总和 II
___
#### 数组
___
#### 回溯
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 字符串 |
| 数组 | 栈 | 矩阵 |

# [31. 下一个排列](https://leetcode.cn/problems/next-permutation){#31}

{{< tabs "31" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
        if ~i:
            j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1 :] = nums[i + 1 :][::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }

        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (~i && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (~i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextPermutation(nums []int) {
	n := len(nums)
	i := n - 2
	for ; i >= 0 && nums[i] >= nums[i+1]; i-- {
	}
	if i >= 0 {
		for j := n - 1; j > i; j-- {
			if nums[j] > nums[i] {
				nums[i], nums[j] = nums[j], nums[i]
				break
			}
		}
	}
	for j, k := i+1, n-1; j < k; j, k = j+1, k-1 {
		nums[j], nums[k] = nums[k], nums[j]
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextPermutation(nums: number[]): void {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        for (let j = n - 1; j > i; --j) {
            if (nums[j] > nums[i]) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
                break;
            }
        }
    }
    for (let j = n - 1; j > i; --j, ++i) {
        [nums[i + 1], nums[j]] = [nums[j], nums[i + 1]];
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        let j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public void NextPermutation(int[] nums) {
        int n = nums.Length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }
        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer[] $nums
     * @return void
     */

    function nextPermutation(&$nums) {
        $n = count($nums);
        $i = $n - 2;
        while ($i >= 0 && $nums[$i] >= $nums[$i + 1]) {
            $i--;
        }
        if ($i >= 0) {
            $j = $n - 1;
            while ($j >= $i && $nums[$j] <= $nums[$i]) {
                $j--;
            }
            $temp = $nums[$i];
            $nums[$i] = $nums[$j];
            $nums[$j] = $temp;
        }
        $this->reverse($nums, $i + 1, $n - 1);
    }

    function reverse(&$nums, $start, $end) {
        while ($start < $end) {
            $temp = $nums[$start];
            $nums[$start] = $nums[$end];
            $nums[$end] = $temp;
            $start++;
            $end--;
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

<p>整数数组的一个 <strong>排列</strong>&nbsp; 就是将其所有成员以序列或线性顺序排列。</p>

<ul>
	<li>例如，<code>arr = [1,2,3]</code> ，以下这些都可以视作 <code>arr</code> 的排列：<code>[1,2,3]</code>、<code>[1,3,2]</code>、<code>[3,1,2]</code>、<code>[2,3,1]</code> 。</li>
</ul>

<p>整数数组的 <strong>下一个排列</strong> 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 <strong>下一个排列</strong> 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。</p>

<ul>
	<li>例如，<code>arr = [1,2,3]</code> 的下一个排列是 <code>[1,3,2]</code> 。</li>
	<li>类似地，<code>arr = [2,3,1]</code> 的下一个排列是 <code>[3,1,2]</code> 。</li>
	<li>而 <code>arr = [3,2,1]</code> 的下一个排列是 <code>[1,2,3]</code> ，因为 <code>[3,2,1]</code> 不存在一个字典序更大的排列。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> ，找出 <code>nums</code> 的下一个排列。</p>

<p>必须<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地 </a></strong>修改，只允许使用额外常数空间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[1,3,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1]
<strong>输出：</strong>[1,2,3]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,5]
<strong>输出：</strong>[1,5,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们先从后往前遍历数组 $nums$，找到第一个满足 $nums[i] \lt nums[i + 1]$ 的位置 $i$，那么 $nums[i]$ 就是我们需要交换的元素，而 $nums[i + 1]$ 到 $nums[n - 1]$ 的元素是一个降序序列。

接下来，我们再从后往前遍历数组 $nums$，找到第一个满足 $nums[j] \gt nums[i]$ 的位置 $j$，然后我们交换 $nums[i]$ 和 $nums[j]$。最后，我们将 $nums[i + 1]$ 到 $nums[n - 1]$ 的元素反转，即可得到下一个排列。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
        if ~i:
            j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1 :] = nums[i + 1 :][::-1]
```

#### Java

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }

        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (~i && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (~i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

#### Go

```go
func nextPermutation(nums []int) {
	n := len(nums)
	i := n - 2
	for ; i >= 0 && nums[i] >= nums[i+1]; i-- {
	}
	if i >= 0 {
		for j := n - 1; j > i; j-- {
			if nums[j] > nums[i] {
				nums[i], nums[j] = nums[j], nums[i]
				break
			}
		}
	}
	for j, k := i+1, n-1; j < k; j, k = j+1, k-1 {
		nums[j], nums[k] = nums[k], nums[j]
	}
}
```

#### TypeScript

```ts
function nextPermutation(nums: number[]): void {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        for (let j = n - 1; j > i; --j) {
            if (nums[j] > nums[i]) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
                break;
            }
        }
    }
    for (let j = n - 1; j > i; --j, ++i) {
        [nums[i + 1], nums[j]] = [nums[j], nums[i + 1]];
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        let j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
};
```

#### C#

```cs
public class Solution {
    public void NextPermutation(int[] nums) {
        int n = nums.Length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }
        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer[] $nums
     * @return void
     */

    function nextPermutation(&$nums) {
        $n = count($nums);
        $i = $n - 2;
        while ($i >= 0 && $nums[$i] >= $nums[$i + 1]) {
            $i--;
        }
        if ($i >= 0) {
            $j = $n - 1;
            while ($j >= $i && $nums[$j] <= $nums[$i]) {
                $j--;
            }
            $temp = $nums[$i];
            $nums[$i] = $nums[$j];
            $nums[$j] = $temp;
        }
        $this->reverse($nums, $i + 1, $n - 1);
    }

    function reverse(&$nums, $start, $end) {
        while ($start < $end) {
            $temp = $nums[$start];
            $nums[$start] = $nums[$end];
            $nums[$end] = $temp;
            $start++;
            $end--;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [32. 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses){#32}

{{< tabs "32" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        ans = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    ans = max(ans, i - stack[-1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s.charAt(i - 1) == ')') {
                if (s.charAt(i - 2) == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s.charAt(j - 1) == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.max(ans, f[i]);
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
    int longestValidParentheses(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
            }
        }
        return *max_element(f, f + n + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestValidParentheses(s string) int {
	ans := 0
	stack := []int{-1}
	for i, v := range s {
		if v == '(' {
			stack = append(stack, i)
		} else {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
			} else {
				if ans < i-stack[len(stack)-1] {
					ans = i - stack[len(stack)-1]
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestValidParentheses(s: string): number {
    let max_length: number = 0;
    const stack: number[] = [-1];
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) == '(') {
            stack.push(i);
        } else {
            stack.pop();

            if (stack.length === 0) {
                stack.push(i);
            } else {
                max_length = Math.max(max_length, i - stack[stack.length - 1]);
            }
        }
    }

    return max_length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut stack = vec![-1];
        let mut res = 0;
        for i in 0..s.len() {
            if let Some('(') = s.chars().nth(i) {
                stack.push(i as i32);
            } else {
                stack.pop().unwrap();
                if stack.is_empty() {
                    stack.push(i as i32);
                } else {
                    res = std::cmp::max(res, (i as i32) - stack.last().unwrap());
                }
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function (s) {
    let ans = 0;
    const stack = [-1];
    for (i = 0; i < s.length; i++) {
        if (s.charAt(i) === '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.length === 0) {
                stack.push(i);
            } else {
                ans = Math.max(ans, i - stack[stack.length - 1]);
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LongestValidParentheses(string s) {
        int n = s.Length;
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.Max(ans, f[i]);
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $s
     * @return integer
     */

    function longestValidParentheses($s) {
        $stack = [];
        $maxLength = 0;

        array_push($stack, -1);
        for ($i = 0; $i < strlen($s); $i++) {
            if ($s[$i] === '(') {
                array_push($stack, $i);
            } else {
                array_pop($stack);

                if (empty($stack)) {
                    array_push($stack, $i);
                } else {
                    $length = $i - end($stack);
                    $maxLength = max($maxLength, $length);
                }
            }
        }
        return $maxLength;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个只包含 <code>'('</code> 和 <code>')'</code> 的字符串，找出最长有效（格式正确且连续）括号 <span data-keyword="substring">子串</span> 的长度。</p>

<p>左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如&nbsp;<code>"(()())"</code>。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "(()"
<strong>输出：</strong>2
<strong>解释：</strong>最长有效括号子串是 "()"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = ")()())"
<strong>输出：</strong>4
<strong>解释：</strong>最长有效括号子串是 "()()"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = ""
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s[i]</code> 为 <code>'('</code> 或 <code>')'</code></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $s[i-1]$ 结尾的最长有效括号的长度，那么答案就是 $\max\limits_{i=1}^n f[i]$。

-   如果 $s[i-1]$ 是左括号，那么以 $s[i-1]$ 结尾的最长有效括号的长度一定为 $0$，因此 $f[i] = 0$。
-   如果 $s[i-1]$ 是右括号，有以下两种情况：
    -   如果 $s[i-2]$ 是左括号，那么以 $s[i-1]$ 结尾的最长有效括号的长度为 $f[i-2] + 2$。
    -   如果 $s[i-2]$ 是右括号，那么以 $s[i-1]$ 结尾的最长有效括号的长度为 $f[i-1] + 2$，但是还需要考虑 $s[i-f[i-1]-2]$ 是否是左括号，如果是左括号，那么以 $s[i-1]$ 结尾的最长有效括号的长度为 $f[i-1] + 2 + f[i-f[i-1]-2]$。

因此，我们可以得到状态转移方程：

$$
\begin{cases}
f[i] = 0, & \textit{if } s[i-1] = '(',\\
f[i] = f[i-2] + 2, & \textit{if } s[i-1] = ')' \textit{ and } s[i-2] = '(',\\
f[i] = f[i-1] + 2 + f[i-f[i-1]-2], & \textit{if } s[i-1] = ')' \textit{ and } s[i-2] = ')' \textit{ and } s[i-f[i-1]-2] = '(',\\
\end{cases}
$$

最后返回 $\max\limits_{i=1}^n f[i]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        f = [0] * (n + 1)
        for i, c in enumerate(s, 1):
            if c == ")":
                if i > 1 and s[i - 2] == "(":
                    f[i] = f[i - 2] + 2
                else:
                    j = i - f[i - 1] - 1
                    if j and s[j - 1] == "(":
                        f[i] = f[i - 1] + 2 + f[j - 1]
        return max(f)
```

#### Java

```java
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s.charAt(i - 1) == ')') {
                if (s.charAt(i - 2) == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s.charAt(j - 1) == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.max(ans, f[i]);
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
    int longestValidParentheses(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
            }
        }
        return *max_element(f, f + n + 1);
    }
};
```

#### Go

```go
func longestValidParentheses(s string) int {
	n := len(s)
	f := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if s[i-1] == ')' {
			if s[i-2] == '(' {
				f[i] = f[i-2] + 2
			} else if j := i - f[i-1] - 1; j > 0 && s[j-1] == '(' {
				f[i] = f[i-1] + 2 + f[j-1]
			}
		}
	}
	return slices.Max(f)
}
```

#### TypeScript

```ts
function longestValidParentheses(s: string): number {
    const n = s.length;
    const f: number[] = new Array(n + 1).fill(0);
    for (let i = 2; i <= n; ++i) {
        if (s[i - 1] === ')') {
            if (s[i - 2] === '(') {
                f[i] = f[i - 2] + 2;
            } else {
                const j = i - f[i - 1] - 1;
                if (j && s[j - 1] === '(') {
                    f[i] = f[i - 1] + 2 + f[j - 1];
                }
            }
        }
    }
    return Math.max(...f);
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut ans = 0;
        let mut f = vec![0; s.len() + 1];
        for i in 2..=s.len() {
            if s.chars().nth(i - 1).unwrap() == ')' {
                if s.chars().nth(i - 2).unwrap() == '(' {
                    f[i] = f[i - 2] + 2;
                } else if (i as i32) - f[i - 1] - 1 > 0
                    && s.chars().nth(i - (f[i - 1] as usize) - 2).unwrap() == '('
                {
                    f[i] = f[i - 1] + 2 + f[i - (f[i - 1] as usize) - 2];
                }
                ans = ans.max(f[i]);
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function (s) {
    const n = s.length;
    const f = new Array(n + 1).fill(0);
    for (let i = 2; i <= n; ++i) {
        if (s[i - 1] === ')') {
            if (s[i - 2] === '(') {
                f[i] = f[i - 2] + 2;
            } else {
                const j = i - f[i - 1] - 1;
                if (j && s[j - 1] === '(') {
                    f[i] = f[i - 1] + 2 + f[j - 1];
                }
            }
        }
    }
    return Math.max(...f);
};
```

#### C#

```cs
public class Solution {
    public int LongestValidParentheses(string s) {
        int n = s.Length;
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.Max(ans, f[i]);
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：使用栈

-   使用栈来存储左括号的索引，栈底元素初始化为 `-1`，用于辅助计算有效括号的长度。
-   遍历字符串，对于每个字符：
    -   如果是左括号，将当前位置压入栈。
    -   如果是右括号，弹出栈顶元素表示匹配了一个左括号。
        -   如果栈为空，说明当前右括号无法匹配，将当前位置压入栈作为新的起点。
        -   如果栈不为空，计算当前有效括号子串的长度，更新最大长度。
-   最终返回最大长度。

总结：这个算法的关键在于维护一个线，栈内存放的是左括号的索引，通过弹出和压入的操作来更新有效括号子串的长度。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        ans = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    ans = max(ans, i - stack[-1])
        return ans
```

#### Go

```go
func longestValidParentheses(s string) int {
	ans := 0
	stack := []int{-1}
	for i, v := range s {
		if v == '(' {
			stack = append(stack, i)
		} else {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
			} else {
				if ans < i-stack[len(stack)-1] {
					ans = i - stack[len(stack)-1]
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestValidParentheses(s: string): number {
    let max_length: number = 0;
    const stack: number[] = [-1];
    for (let i = 0; i < s.length; i++) {
        if (s.charAt(i) == '(') {
            stack.push(i);
        } else {
            stack.pop();

            if (stack.length === 0) {
                stack.push(i);
            } else {
                max_length = Math.max(max_length, i - stack[stack.length - 1]);
            }
        }
    }

    return max_length;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut stack = vec![-1];
        let mut res = 0;
        for i in 0..s.len() {
            if let Some('(') = s.chars().nth(i) {
                stack.push(i as i32);
            } else {
                stack.pop().unwrap();
                if stack.is_empty() {
                    stack.push(i as i32);
                } else {
                    res = std::cmp::max(res, (i as i32) - stack.last().unwrap());
                }
            }
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function (s) {
    let ans = 0;
    const stack = [-1];
    for (i = 0; i < s.length; i++) {
        if (s.charAt(i) === '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.length === 0) {
                stack.push(i);
            } else {
                ans = Math.max(ans, i - stack[stack.length - 1]);
            }
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param string $s
     * @return integer
     */

    function longestValidParentheses($s) {
        $stack = [];
        $maxLength = 0;

        array_push($stack, -1);
        for ($i = 0; $i < strlen($s); $i++) {
            if ($s[$i] === '(') {
                array_push($stack, $i);
            } else {
                array_pop($stack);

                if (empty($stack)) {
                    array_push($stack, $i);
                } else {
                    $length = $i - end($stack);
                    $maxLength = max($maxLength, $length);
                }
            }
        }
        return $maxLength;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array){#33}

{{< tabs "33" >}}

{{% tab "python" %}}
```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[n - 1]:
                    left = mid + 1
                else:
                    right = mid
        return left if nums[left] == target else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func search(nums []int, target int) int {
	n := len(nums)
	left, right := 0, n-1
	for left < right {
		mid := (left + right) >> 1
		if nums[0] <= nums[mid] {
			if nums[0] <= target && target <= nums[mid] {
				right = mid
			} else {
				left = mid + 1
			}
		} else {
			if nums[mid] < target && target <= nums[n-1] {
				left = mid + 1
			} else {
				right = mid
			}
		}
	}
	if nums[left] == target {
		return left
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function search(nums: number[], target: number): number {
    const n = nums.length;
    let left = 0,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return nums[left] == target ? left : -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l <= r {
            let mid = (l + r) >> 1;
            if nums[mid] == target {
                return mid as i32;
            }

            if nums[l] <= nums[mid] {
                if target < nums[mid] && target >= nums[l] {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if target > nums[mid] && target <= nums[r] {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        -1
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    const n = nums.length;
    let left = 0,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return nums[left] == target ? left : -1;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer[] $nums
     * @param integer $target
     * @return integer
     */

    function search($nums, $target) {
        $foundKey = -1;
        foreach ($nums as $key => $value) {
            if ($value === $target) {
                $foundKey = $key;
            }
        }
        return $foundKey;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>整数数组 <code>nums</code> 按升序排列，数组中的值 <strong>互不相同</strong> 。</p>

<p>在传递给函数之前，<code>nums</code> 在预先未知的某个下标 <code>k</code>（<code>0 &lt;= k &lt; nums.length</code>）上进行了 <strong>向左旋转</strong>，使数组变为 <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code>（下标 <strong>从 0 开始</strong> 计数）。例如， <code>[0,1,2,4,5,6,7]</code> 下标&nbsp;<code>3</code>&nbsp;上向左旋转后可能变为&nbsp;<code>[4,5,6,7,0,1,2]</code> 。</p>

<p>给你 <strong>旋转后</strong> 的数组 <code>nums</code> 和一个整数 <code>target</code> ，如果 <code>nums</code> 中存在这个目标值 <code>target</code> ，则返回它的下标，否则返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>你必须设计一个时间复杂度为 <code>O(log n)</code> 的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>4,5,6,7,0,1,2]</code>, target = 0
<strong>输出：</strong>4
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>4,5,6,7,0,1,2]</code>, target = 3
<strong>输出：</strong>-1</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], target = 0
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 中的每个值都 <strong>独一无二</strong></li>
	<li>题目数据保证 <code>nums</code> 在预先未知的某个下标上进行了旋转</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们使用二分，将数组分割成 $[left,.. mid]$, $[mid + 1,.. right]$ 两部分，这时候可以发现，其中有一部分一定是有序的。

因此，我们可以根据有序的那一部分，判断 $target$ 是否在这一部分中：

-   若 $[0,.. mid]$ 范围内的元素构成有序数组：
    -   若满足 $nums[0] \leq target \leq nums[mid]$，那么我们搜索范围可以缩小为 $[left,.. mid]$；
    -   否则，在 $[mid + 1,.. right]$ 中查找；
-   若 $[mid + 1, n - 1]$ 范围内的元素构成有序数组：
    -   若满足 $nums[mid] \lt target \leq nums[n - 1]$，那么我们搜索范围可以缩小为 $[mid + 1,.. right]$；
    -   否则，在 $[left,.. mid]$ 中查找。

二分查找终止条件是 $left \geq right$，若结束后发现 $nums[left]$ 与 $target$ 不等，说明数组中不存在值为 $target$ 的元素，返回 $-1$，否则返回下标 $left$。

时间复杂度 $O(\log n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[n - 1]:
                    left = mid + 1
                else:
                    right = mid
        return left if nums[left] == target else -1
```

#### Java

```java
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
```

#### Go

```go
func search(nums []int, target int) int {
	n := len(nums)
	left, right := 0, n-1
	for left < right {
		mid := (left + right) >> 1
		if nums[0] <= nums[mid] {
			if nums[0] <= target && target <= nums[mid] {
				right = mid
			} else {
				left = mid + 1
			}
		} else {
			if nums[mid] < target && target <= nums[n-1] {
				left = mid + 1
			} else {
				right = mid
			}
		}
	}
	if nums[left] == target {
		return left
	}
	return -1
}
```

#### TypeScript

```ts
function search(nums: number[], target: number): number {
    const n = nums.length;
    let left = 0,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return nums[left] == target ? left : -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l <= r {
            let mid = (l + r) >> 1;
            if nums[mid] == target {
                return mid as i32;
            }

            if nums[l] <= nums[mid] {
                if target < nums[mid] && target >= nums[l] {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if target > nums[mid] && target <= nums[r] {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        -1
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    const n = nums.length;
    let left = 0,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return nums[left] == target ? left : -1;
};
```

#### C#

```cs
public class Solution {
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer[] $nums
     * @param integer $target
     * @return integer
     */

    function search($nums, $target) {
        $foundKey = -1;
        foreach ($nums as $key => $value) {
            if ($value === $target) {
                $foundKey = $key;
            }
        }
        return $foundKey;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array){#34}

{{< tabs "34" >}}

{{% tab "python" %}}
```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)
        r = bisect_left(nums, target + 1)
        return [-1, -1] if l == r else [l, r - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search(nums, target);
        int r = search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r) {
            return {-1, -1};
        }
        return {l, r - 1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func searchRange(nums []int, target int) []int {
	l := sort.SearchInts(nums, target)
	r := sort.SearchInts(nums, target+1)
	if l == r {
		return []int{-1, -1}
	}
	return []int{l, r - 1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function searchRange(nums: number[], target: number): number[] {
    const search = (x: number): number => {
        let [left, right] = [0, nums.length];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const l = search(target);
    const r = search(target + 1);
    return l === r ? [-1, -1] : [l, r - 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let n = nums.len();
        let search = |x| {
            let mut left = 0;
            let mut right = n;
            while left < right {
                let mid = left + (right - left) / 2;
                if nums[mid] < x {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            left
        };
        let l = search(target);
        let r = search(target + 1);
        if l == r {
            return vec![-1, -1];
        }
        vec![l as i32, (r - 1) as i32]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    function search(x) {
        let left = 0,
            right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    const l = search(target);
    const r = search(target + 1);
    return l == r ? [-1, -1] : [l, r - 1];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        int l = Search(nums, target);
        int r = Search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int Search(int[] nums, int x) {
        int left = 0, right = nums.Length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function searchRange($nums, $target) {
        $search = function ($x) use ($nums) {
            $left = 0;
            $right = count($nums);
            while ($left < $right) {
                $mid = intdiv($left + $right, 2);
                if ($nums[$mid] >= $x) {
                    $right = $mid;
                } else {
                    $left = $mid + 1;
                }
            }
            return $left;
        };

        $l = $search($target);
        $r = $search($target + 1);
        return $l === $r ? [-1, -1] : [$l, $r - 1];
    }
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        val left = this.search(nums, target)
        val right = this.search(nums, target + 1)
        return if (left == right) intArrayOf(-1, -1) else intArrayOf(left, right - 1)
    }

    private fun search(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size
        while (left < right) {
            val middle = (left + right) / 2
            if (nums[middle] < target) {
                left = middle + 1
            } else {
                right = middle
            }
        }
        return left
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个按照非递减顺序排列的整数数组 <code>nums</code>，和一个目标值 <code>target</code>。请你找出给定目标值在数组中的开始位置和结束位置。</p>

<p>如果数组中不存在目标值 <code>target</code>，返回&nbsp;<code>[-1, -1]</code>。</p>

<p>你必须设计并实现时间复杂度为&nbsp;<code>O(log n)</code>&nbsp;的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>5,7,7,8,8,10]</code>, target = 8
<strong>输出：</strong>[3,4]</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<code>5,7,7,8,8,10]</code>, target = 6
<strong>输出：</strong>[-1,-1]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [], target = 0
<strong>输出：</strong>[-1,-1]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;是一个非递减数组</li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以进行两次二分查找，分别查找出左边界和右边界。

时间复杂度 $O(\log n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)
        r = bisect_left(nums, target + 1)
        return [-1, -1] if l == r else [l, r - 1]
```

#### Java

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search(nums, target);
        int r = search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r) {
            return {-1, -1};
        }
        return {l, r - 1};
    }
};
```

#### Go

```go
func searchRange(nums []int, target int) []int {
	l := sort.SearchInts(nums, target)
	r := sort.SearchInts(nums, target+1)
	if l == r {
		return []int{-1, -1}
	}
	return []int{l, r - 1}
}
```

#### TypeScript

```ts
function searchRange(nums: number[], target: number): number[] {
    const search = (x: number): number => {
        let [left, right] = [0, nums.length];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const l = search(target);
    const r = search(target + 1);
    return l === r ? [-1, -1] : [l, r - 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let n = nums.len();
        let search = |x| {
            let mut left = 0;
            let mut right = n;
            while left < right {
                let mid = left + (right - left) / 2;
                if nums[mid] < x {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            left
        };
        let l = search(target);
        let r = search(target + 1);
        if l == r {
            return vec![-1, -1];
        }
        vec![l as i32, (r - 1) as i32]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    function search(x) {
        let left = 0,
            right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    const l = search(target);
    const r = search(target + 1);
    return l == r ? [-1, -1] : [l, r - 1];
};
```

#### C#

```cs
public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        int l = Search(nums, target);
        int r = Search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int Search(int[] nums, int x) {
        int left = 0, right = nums.Length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function searchRange($nums, $target) {
        $search = function ($x) use ($nums) {
            $left = 0;
            $right = count($nums);
            while ($left < $right) {
                $mid = intdiv($left + $right, 2);
                if ($nums[$mid] >= $x) {
                    $right = $mid;
                } else {
                    $left = $mid + 1;
                }
            }
            return $left;
        };

        $l = $search($target);
        $r = $search($target + 1);
        return $l === $r ? [-1, -1] : [$l, $r - 1];
    }
}
```

#### Kotlin

```kotlin
class Solution {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        val left = this.search(nums, target)
        val right = this.search(nums, target + 1)
        return if (left == right) intArrayOf(-1, -1) else intArrayOf(left, right - 1)
    }

    private fun search(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size
        while (left < right) {
            val middle = (left + right) / 2
            if (nums[middle] < target) {
                left = middle + 1
            } else {
                right = middle
            }
        }
        return left
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position){#35}

{{< tabs "35" >}}

{{% tab "python" %}}
```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bisect_left(nums, target)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i = Arrays.binarySearch(nums, target);
        return i < 0 ? -i - 1 : i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func searchInsert(nums []int, target int) int {
	return sort.SearchInts(nums, target)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function searchInsert(nums: number[], target: number): number {
    let [l, r] = [0, nums.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len();
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] >= target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
    let [l, r] = [0, nums.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        $l = 0;
        $r = count($nums);
        while ($l < $r) {
            $mid = $l + $r >> 1;
            if ($nums[$mid] >= $target) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }
        return $l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>

<p>请必须使用时间复杂度为 <code>O(log n)</code> 的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 5
<strong>输出:</strong> 2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 2
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 7
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 为&nbsp;<strong>无重复元素&nbsp;</strong>的&nbsp;<strong>升序&nbsp;</strong>排列数组</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

由于 $nums$ 数组已经有序，因此我们可以使用二分查找的方法找到目标值 $target$ 的插入位置。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l
```

#### Java

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
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
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func searchInsert(nums []int, target int) int {
	l, r := 0, len(nums)
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function searchInsert(nums: number[], target: number): number {
    let [l, r] = [0, nums.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len();
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] >= target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
    let [l, r] = [0, nums.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        $l = 0;
        $r = count($nums);
        while ($l < $r) {
            $mid = $l + $r >> 1;
            if ($nums[$mid] >= $target) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }
        return $l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找（内置函数）

我们也可以直接使用内置函数进行二分查找。

时间复杂度 $O(\log n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bisect_left(nums, target)
```

#### Java

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i = Arrays.binarySearch(nums, target);
        return i < 0 ? -i - 1 : i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

#### Go

```go
func searchInsert(nums []int, target int) int {
	return sort.SearchInts(nums, target)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [36. 有效的数独](https://leetcode.cn/problems/valid-sudoku){#36}

{{< tabs "36" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        sub = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                num = int(c) - 1
                k = i // 3 * 3 + j // 3
                if row[i][num] or col[j][num] or sub[k][num]:
                    return False
                row[i][num] = True
                col[j][num] = True
                sub[k][num] = True
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] sub = new boolean[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValidSudoku(board [][]byte) bool {
	row, col, sub := [9][9]bool{}, [9][9]bool{}, [9][9]bool{}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			num := board[i][j] - byte('1')
			if num < 0 || num > 9 {
				continue
			}
			k := i/3*3 + j/3
			if row[i][num] || col[j][num] || sub[k][num] {
				return false
			}
			row[i][num] = true
			col[j][num] = true
			sub[k][num] = true
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isValidSudoku(board: string[][]): boolean {
    const row: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    const col: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    const sub: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            const num = board[i][j].charCodeAt(0) - '1'.charCodeAt(0);
            if (num < 0 || num > 8) {
                continue;
            }
            const k = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (row[i][num] || col[j][num] || sub[k][num]) {
                return false;
            }
            row[i][num] = true;
            col[j][num] = true;
            sub[k][num] = true;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row = vec![vec![false; 9]; 9];
        let mut col = vec![vec![false; 9]; 9];
        let mut sub = vec![vec![false; 9]; 9];

        for i in 0..9 {
            for j in 0..9 {
                let c = board[i][j];
                if c == '.' {
                    continue;
                }
                let num = (c as u8 - b'0' - 1) as usize;
                let k = i / 3 * 3 + j / 3;
                if row[i][num] || col[j][num] || sub[k][num] {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    const row = [...Array(9)].map(() => Array(9).fill(false));
    const col = [...Array(9)].map(() => Array(9).fill(false));
    const sub = [...Array(9)].map(() => Array(9).fill(false));
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            const num = board[i][j].charCodeAt() - '1'.charCodeAt();
            if (num < 0 || num > 8) {
                continue;
            }
            const k = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (row[i][num] || col[j][num] || sub[k][num]) {
                return false;
            }
            row[i][num] = true;
            col[j][num] = true;
            sub[k][num] = true;
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        bool[,] row = new bool[9, 9];
        bool[,] col = new bool[9, 9];
        bool[,] sub = new bool[9, 9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = (i / 3) * 3 + (j / 3);
                if (row[i, num] || col[j, num] || sub[k, num]) {
                    return false;
                }
                row[i, num] = true;
                col[j, num] = true;
                sub[k, num] = true;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String[][] $board
     * @return Boolean
     */
    function isValidSudoku($board) {
        $row = array_fill(0, 9, array_fill(0, 9, false));
        $col = array_fill(0, 9, array_fill(0, 9, false));
        $sub = array_fill(0, 9, array_fill(0, 9, false));

        for ($i = 0; $i < 9; $i++) {
            for ($j = 0; $j < 9; $j++) {
                $c = $board[$i][$j];
                if ($c === '.') {
                    continue;
                }
                $num = intval($c) - 1;
                $k = intdiv($i, 3) * 3 + intdiv($j, 3);
                if ($row[$i][$num] || $col[$j][$num] || $sub[$k][$num]) {
                    return false;
                }
                $row[$i][$num] = true;
                $col[$j][$num] = true;
                $sub[$k][$num] = true;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你判断一个&nbsp;<code>9 x 9</code> 的数独是否有效。只需要<strong> 根据以下规则</strong> ，验证已经填入的数字是否有效即可。</p>

<ol>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一行只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一列只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一个以粗实线分隔的&nbsp;<code>3x3</code>&nbsp;宫内只能出现一次。（请参考示例图）</li>
</ol>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li>一个有效的数独（部分已被填充）不一定是可解的。</li>
	<li>只需要根据以上规则，验证已经填入的数字是否有效即可。</li>
	<li>空白格用&nbsp;<code>'.'</code>&nbsp;表示。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0036.Valid%20Sudoku/images/250px-sudoku-by-l2g-20050714svg.png" style="height:250px; width:250px" />
<pre>
<strong>输入：</strong>board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>输出：</strong>false
<strong>解释：</strong>除了第一行的第一个数字从<strong> 5</strong> 改为 <strong>8 </strong>以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> 是一位数字（<code>1-9</code>）或者 <code>'.'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

有效的数独满足以下三个条件：

-   每一行中的数字都不重复；
-   每一列中的数字都不重复；
-   每一个 $3 \times 3$ 的宫格中的数字都不重复。

遍历数独，对于每个数字，判断其所在的行、列 以及 $3 \times 3$ 的宫格是否已经出现过该数字，如果是，则返回 `false`。遍历结束，返回 `true`。

时间复杂度 $O(C)$，空间复杂度 $O(C)$，其中 $C$ 是数独中的空格数。本题中 $C=81$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        sub = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                num = int(c) - 1
                k = i // 3 * 3 + j // 3
                if row[i][num] or col[j][num] or sub[k][num]:
                    return False
                row[i][num] = True
                col[j][num] = True
                sub[k][num] = True
        return True
```

#### Java

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] sub = new boolean[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isValidSudoku(board [][]byte) bool {
	row, col, sub := [9][9]bool{}, [9][9]bool{}, [9][9]bool{}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			num := board[i][j] - byte('1')
			if num < 0 || num > 9 {
				continue
			}
			k := i/3*3 + j/3
			if row[i][num] || col[j][num] || sub[k][num] {
				return false
			}
			row[i][num] = true
			col[j][num] = true
			sub[k][num] = true
		}
	}
	return true
}
```

#### TypeScript

```ts
function isValidSudoku(board: string[][]): boolean {
    const row: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    const col: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    const sub: boolean[][] = Array.from({ length: 9 }, () =>
        Array.from({ length: 9 }, () => false),
    );
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            const num = board[i][j].charCodeAt(0) - '1'.charCodeAt(0);
            if (num < 0 || num > 8) {
                continue;
            }
            const k = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (row[i][num] || col[j][num] || sub[k][num]) {
                return false;
            }
            row[i][num] = true;
            col[j][num] = true;
            sub[k][num] = true;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row = vec![vec![false; 9]; 9];
        let mut col = vec![vec![false; 9]; 9];
        let mut sub = vec![vec![false; 9]; 9];

        for i in 0..9 {
            for j in 0..9 {
                let c = board[i][j];
                if c == '.' {
                    continue;
                }
                let num = (c as u8 - b'0' - 1) as usize;
                let k = i / 3 * 3 + j / 3;
                if row[i][num] || col[j][num] || sub[k][num] {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    const row = [...Array(9)].map(() => Array(9).fill(false));
    const col = [...Array(9)].map(() => Array(9).fill(false));
    const sub = [...Array(9)].map(() => Array(9).fill(false));
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            const num = board[i][j].charCodeAt() - '1'.charCodeAt();
            if (num < 0 || num > 8) {
                continue;
            }
            const k = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (row[i][num] || col[j][num] || sub[k][num]) {
                return false;
            }
            row[i][num] = true;
            col[j][num] = true;
            sub[k][num] = true;
        }
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        bool[,] row = new bool[9, 9];
        bool[,] col = new bool[9, 9];
        bool[,] sub = new bool[9, 9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = (i / 3) * 3 + (j / 3);
                if (row[i, num] || col[j, num] || sub[k, num]) {
                    return false;
                }
                row[i, num] = true;
                col[j, num] = true;
                sub[k, num] = true;
            }
        }
        return true;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String[][] $board
     * @return Boolean
     */
    function isValidSudoku($board) {
        $row = array_fill(0, 9, array_fill(0, 9, false));
        $col = array_fill(0, 9, array_fill(0, 9, false));
        $sub = array_fill(0, 9, array_fill(0, 9, false));

        for ($i = 0; $i < 9; $i++) {
            for ($j = 0; $j < 9; $j++) {
                $c = $board[$i][$j];
                if ($c === '.') {
                    continue;
                }
                $num = intval($c) - 1;
                $k = intdiv($i, 3) * 3 + intdiv($j, 3);
                if ($row[$i][$num] || $col[$j][$num] || $sub[$k][$num]) {
                    return false;
                }
                $row[$i][$num] = true;
                $col[$j][$num] = true;
                $sub[$k][$num] = true;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [37. 解数独](https://leetcode.cn/problems/sudoku-solver){#37}

{{< tabs "37" >}}

{{% tab "python" %}}
```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def dfs(k):
            nonlocal ok
            if k == len(t):
                ok = True
                return
            i, j = t[k]
            for v in range(9):
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
                    board[i][j] = str(v + 1)
                    dfs(k + 1)
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False
                if ok:
                    return

        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]
        t = []
        ok = False
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    t.append((i, j))
                else:
                    v = int(board[i][j]) - 1
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
        dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private boolean ok;
    private char[][] board;
    private List<Integer> t = new ArrayList<>();
    private boolean[][] row = new boolean[9][9];
    private boolean[][] col = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.add(i * 9 + j);
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        dfs(0);
    }

    private void dfs(int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t.get(k) / 9, j = t.get(k) % 9;
        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                board[i][j] = (char) (v + '1');
                dfs(k + 1);
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
            }
            if (ok) {
                return;
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
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[3][3][9] = {false};
        bool ok = false;
        vector<pair<int, int>> t;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        auto dfs = [&](this auto&& dfs, int k) -> void {
            if (k == t.size()) {
                ok = true;
                return;
            }
            int i = t[k].first, j = t[k].second;
            for (int v = 0; v < 9; ++v) {
                if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                    board[i][j] = v + '1';
                    dfs(k + 1);
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
                }
                if (ok) {
                    return;
                }
            }
        };
        dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func solveSudoku(board [][]byte) {
	var row, col [9][9]bool
	var block [3][3][9]bool
	var t [][2]int
	ok := false
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				t = append(t, [2]int{i, j})
			} else {
				v := int(board[i][j] - '1')
				row[i][v], col[j][v], block[i/3][j/3][v] = true, true, true
			}
		}
	}
	var dfs func(int)
	dfs = func(k int) {
		if k == len(t) {
			ok = true
			return
		}
		i, j := t[k][0], t[k][1]
		for v := 0; v < 9; v++ {
			if !row[i][v] && !col[j][v] && !block[i/3][j/3][v] {
				row[i][v], col[j][v], block[i/3][j/3][v] = true, true, true
				board[i][j] = byte(v + '1')
				dfs(k + 1)
				row[i][v], col[j][v], block[i/3][j/3][v] = false, false, false
			}
			if ok {
				return
			}
		}
	}
	dfs(0)
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public void SolveSudoku(char[][] board) {
        bool[,] row = new bool[9, 9];
        bool[,] col = new bool[9, 9];
        bool[,,] block = new bool[3, 3, 9];
        bool ok = false;
        var t = new List<(int, int)>();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.Add((i, j));
                } else {
                    int v = board[i][j] - '1';
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = true;
                }
            }
        }

        void Dfs(int k) {
            if (k == t.Count) {
                ok = true;
                return;
            }
            var (i, j) = t[k];
            for (int v = 0; v < 9; ++v) {
                if (!row[i, v] && !col[j, v] && !block[i / 3, j / 3, v]) {
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = true;
                    board[i][j] = (char)(v + '1');
                    Dfs(k + 1);
                    if (ok) return;
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = false;
                }
            }
        }

        Dfs(0);
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String[][] $board
     * @return NULL
     */
    function solveSudoku(&$board) {
        $row = array_fill(0, 9, array_fill(0, 9, false));
        $col = array_fill(0, 9, array_fill(0, 9, false));
        $block = array_fill(0, 3, array_fill(0, 3, array_fill(0, 9, false)));
        $ok = false;
        $t = [];

        for ($i = 0; $i < 9; ++$i) {
            for ($j = 0; $j < 9; ++$j) {
                if ($board[$i][$j] === '.') {
                    $t[] = [$i, $j];
                } else {
                    $v = ord($board[$i][$j]) - ord('1');
                    $row[$i][$v] = true;
                    $col[$j][$v] = true;
                    $block[intval($i / 3)][intval($j / 3)][$v] = true;
                }
            }
        }

        $dfs = function ($k) use (&$dfs, &$board, &$row, &$col, &$block, &$ok, &$t) {
            if ($k === count($t)) {
                $ok = true;
                return;
            }
            [$i, $j] = $t[$k];
            for ($v = 0; $v < 9; ++$v) {
                if (!$row[$i][$v] && !$col[$j][$v] && !$block[intval($i / 3)][intval($j / 3)][$v]) {
                    $row[$i][$v] = $col[$j][$v] = $block[intval($i / 3)][intval($j / 3)][$v] = true;
                    $board[$i][$j] = chr($v + ord('1'));
                    $dfs($k + 1);
                    if ($ok) {
                        return;
                    }
                    $row[$i][$v] = $col[$j][$v] = $block[intval($i / 3)][intval($j / 3)][
                        $v
                    ] = false;
                }
            }
        };

        $dfs(0);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个程序，通过填充空格来解决数独问题。</p>

<p>数独的解法需<strong> 遵循如下规则</strong>：</p>

<ol>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一行只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一列只能出现一次。</li>
	<li>数字&nbsp;<code>1-9</code>&nbsp;在每一个以粗实线分隔的&nbsp;<code>3x3</code>&nbsp;宫内只能出现一次。（请参考示例图）</li>
</ol>

<p>数独部分空格内已填入了数字，空白格用&nbsp;<code>'.'</code>&nbsp;表示。</p>

<p>&nbsp;</p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0037.Sudoku%20Solver/images/250px-sudoku-by-l2g-20050714svg.png" style="height:250px; width:250px" />
<pre>
<strong>输入：</strong>board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
<strong>输出：</strong>[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
<strong>解释：</strong>输入的数独如上图所示，唯一有效的解决方案如下所示：

<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0037.Sudoku%20Solver/images/250px-sudoku-by-l2g-20050714_solutionsvg.png" style="height:250px; width:250px" />
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> 是一位数字或者 <code>'.'</code></li>
	<li>题目数据 <strong>保证</strong> 输入数独仅有一个解</li>
</ul>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯

我们用数组 $\textit{row}$, $\textit{col}$, $\textit{box}$ 分别记录每一行、每一列、每个 3x3 宫格中数字是否出现过。如果数字 $i$ 在第 $r$ 行、第 $c$ 列、第 $b$ 个 3x3 宫格中出现过，那么 $\text{row[r][i]}$, $\text{col[c][i]}$, $\text{box[b][i]}$ 都为 $true$。

我们遍历 $\textit{board}$ 中的每一个空格，枚举它可以填入的数字 $v$，如果 $v$ 在当前行、当前列、当前 3x3 宫格中没有出现过，那么我们就可以尝试填入数字 $v$，并继续搜索下一个空格。如果搜索到最后，所有空格填充完毕，那么就说明找到了一个可行解。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def dfs(k):
            nonlocal ok
            if k == len(t):
                ok = True
                return
            i, j = t[k]
            for v in range(9):
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
                    board[i][j] = str(v + 1)
                    dfs(k + 1)
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False
                if ok:
                    return

        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]
        t = []
        ok = False
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    t.append((i, j))
                else:
                    v = int(board[i][j]) - 1
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
        dfs(0)
```

#### Java

```java
class Solution {
    private boolean ok;
    private char[][] board;
    private List<Integer> t = new ArrayList<>();
    private boolean[][] row = new boolean[9][9];
    private boolean[][] col = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.add(i * 9 + j);
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        dfs(0);
    }

    private void dfs(int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t.get(k) / 9, j = t.get(k) % 9;
        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                board[i][j] = (char) (v + '1');
                dfs(k + 1);
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
            }
            if (ok) {
                return;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[3][3][9] = {false};
        bool ok = false;
        vector<pair<int, int>> t;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        auto dfs = [&](this auto&& dfs, int k) -> void {
            if (k == t.size()) {
                ok = true;
                return;
            }
            int i = t[k].first, j = t[k].second;
            for (int v = 0; v < 9; ++v) {
                if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                    board[i][j] = v + '1';
                    dfs(k + 1);
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
                }
                if (ok) {
                    return;
                }
            }
        };
        dfs(0);
    }
};
```

#### Go

```go
func solveSudoku(board [][]byte) {
	var row, col [9][9]bool
	var block [3][3][9]bool
	var t [][2]int
	ok := false
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				t = append(t, [2]int{i, j})
			} else {
				v := int(board[i][j] - '1')
				row[i][v], col[j][v], block[i/3][j/3][v] = true, true, true
			}
		}
	}
	var dfs func(int)
	dfs = func(k int) {
		if k == len(t) {
			ok = true
			return
		}
		i, j := t[k][0], t[k][1]
		for v := 0; v < 9; v++ {
			if !row[i][v] && !col[j][v] && !block[i/3][j/3][v] {
				row[i][v], col[j][v], block[i/3][j/3][v] = true, true, true
				board[i][j] = byte(v + '1')
				dfs(k + 1)
				row[i][v], col[j][v], block[i/3][j/3][v] = false, false, false
			}
			if ok {
				return
			}
		}
	}
	dfs(0)
}
```

#### C#

```cs
public class Solution {
    public void SolveSudoku(char[][] board) {
        bool[,] row = new bool[9, 9];
        bool[,] col = new bool[9, 9];
        bool[,,] block = new bool[3, 3, 9];
        bool ok = false;
        var t = new List<(int, int)>();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.Add((i, j));
                } else {
                    int v = board[i][j] - '1';
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = true;
                }
            }
        }

        void Dfs(int k) {
            if (k == t.Count) {
                ok = true;
                return;
            }
            var (i, j) = t[k];
            for (int v = 0; v < 9; ++v) {
                if (!row[i, v] && !col[j, v] && !block[i / 3, j / 3, v]) {
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = true;
                    board[i][j] = (char)(v + '1');
                    Dfs(k + 1);
                    if (ok) return;
                    row[i, v] = col[j, v] = block[i / 3, j / 3, v] = false;
                }
            }
        }

        Dfs(0);
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String[][] $board
     * @return NULL
     */
    function solveSudoku(&$board) {
        $row = array_fill(0, 9, array_fill(0, 9, false));
        $col = array_fill(0, 9, array_fill(0, 9, false));
        $block = array_fill(0, 3, array_fill(0, 3, array_fill(0, 9, false)));
        $ok = false;
        $t = [];

        for ($i = 0; $i < 9; ++$i) {
            for ($j = 0; $j < 9; ++$j) {
                if ($board[$i][$j] === '.') {
                    $t[] = [$i, $j];
                } else {
                    $v = ord($board[$i][$j]) - ord('1');
                    $row[$i][$v] = true;
                    $col[$j][$v] = true;
                    $block[intval($i / 3)][intval($j / 3)][$v] = true;
                }
            }
        }

        $dfs = function ($k) use (&$dfs, &$board, &$row, &$col, &$block, &$ok, &$t) {
            if ($k === count($t)) {
                $ok = true;
                return;
            }
            [$i, $j] = $t[$k];
            for ($v = 0; $v < 9; ++$v) {
                if (!$row[$i][$v] && !$col[$j][$v] && !$block[intval($i / 3)][intval($j / 3)][$v]) {
                    $row[$i][$v] = $col[$j][$v] = $block[intval($i / 3)][intval($j / 3)][$v] = true;
                    $board[$i][$j] = chr($v + ord('1'));
                    $dfs($k + 1);
                    if ($ok) {
                        return;
                    }
                    $row[$i][$v] = $col[$j][$v] = $block[intval($i / 3)][intval($j / 3)][
                        $v
                    ] = false;
                }
            }
        };

        $dfs(0);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [38. 外观数列](https://leetcode.cn/problems/count-and-say){#38}

{{< tabs "38" >}}

{{% tab "python" %}}
```python
class Solution:
    def countAndSay(self, n: int) -> str:
        s = '1'
        for _ in range(n - 1):
            i = 0
            t = []
            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1
                t.append(str(j - i))
                t.append(str(s[i]))
                i = j
            s = ''.join(t)
        return s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        while (--n > 0) {
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < s.length();) {
                int j = i;
                while (j < s.length() && s.charAt(j) == s.charAt(i)) {
                    ++j;
                }
                t.append((j - i) + "");
                t.append(s.charAt(i));
                i = j;
            }
            s = t.toString();
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
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string t = "";
            for (int i = 0; i < s.size();) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) ++j;
                t += to_string(j - i);
                t += s[i];
                i = j;
            }
            s = t;
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countAndSay(n int) string {
	s := "1"
	for k := 0; k < n-1; k++ {
		t := &strings.Builder{}
		i := 0
		for i < len(s) {
			j := i
			for j < len(s) && s[j] == s[i] {
				j++
			}
			t.WriteString(strconv.Itoa(j - i))
			t.WriteByte(s[i])
			i = j
		}
		s = t.String()
	}
	return s
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countAndSay(n: number): string {
    let s = '1';
    for (let i = 1; i < n; i++) {
        let t = '';
        let cur = s[0];
        let count = 1;
        for (let j = 1; j < s.length; j++) {
            if (s[j] !== cur) {
                t += `${count}${cur}`;
                cur = s[j];
                count = 0;
            }
            count++;
        }
        t += `${count}${cur}`;
        s = t;
    }
    return s;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::iter::once;

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        (1..n)
            .fold(vec![1], |curr, _| {
                let mut next = vec![];
                let mut slow = 0;
                for fast in 0..=curr.len() {
                    if fast == curr.len() || curr[slow] != curr[fast] {
                        next.extend(once((fast - slow) as u8).chain(once(curr[slow])));
                        slow = fast;
                    }
                }
                next
            })
            .into_iter()
            .map(|digit| (digit + b'0') as char)
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
const countAndSay = function (n) {
    let s = '1';

    for (let i = 2; i <= n; i++) {
        let count = 1,
            str = '',
            len = s.length;

        for (let j = 0; j < len; j++) {
            if (j < len - 1 && s[j] === s[j + 1]) {
                count++;
            } else {
                str += `${count}${s[j]}`;
                count = 1;
            }
        }
        s = str;
    }
    return s;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Text;
public class Solution {
    public string CountAndSay(int n) {
        var s = "1";
        while (n > 1)
        {
            var sb = new StringBuilder();
            var lastChar = '1';
            var count = 0;
            foreach (var ch in s)
            {
                if (count > 0 && lastChar == ch)
                {
                    ++count;
                }
                else
                {
                    if (count > 0)
                    {
                        sb.Append(count);
                        sb.Append(lastChar);
                    }
                    lastChar = ch;
                    count = 1;
                }
            }
            if (count > 0)
            {
                sb.Append(count);
                sb.Append(lastChar);
            }
            s = sb.ToString();
            --n;
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer $n
     * @return string
     */

    function countAndSay($n) {
        if ($n <= 0) {
            return '';
        }

        $result = '1';
        for ($i = 2; $i <= $n; $i++) {
            $count = 1;
            $say = '';
            for ($j = 1; $j < strlen($result); $j++) {
                if ($result[$j] == $result[$j - 1]) {
                    $count++;
                } else {
                    $say .= $count . $result[$j - 1];
                    $count = 1;
                }
            }
            $say .= $count . $result[strlen($result) - 1];
            $result = $say;
        }
        return $result;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>「外观数列」是一个数位字符串序列，由递归公式定义：</p>

<ul>
	<li><code>countAndSay(1) = "1"</code></li>
	<li><code>countAndSay(n)</code> 是&nbsp;<code>countAndSay(n-1)</code> 的行程长度编码。</li>
</ul>

<p>&nbsp;</p>

<ul>
</ul>

<p><a href="https://baike.baidu.com/item/%E8%A1%8C%E7%A8%8B%E9%95%BF%E5%BA%A6%E7%BC%96%E7%A0%81/2931940">行程长度编码</a>（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串&nbsp;<code>"3322251"</code>&nbsp;，我们将&nbsp;<code>"33"</code>&nbsp;用&nbsp;<code>"23"</code>&nbsp;替换，将&nbsp;<code>"222"</code>&nbsp;用&nbsp;<code>"32"</code>&nbsp;替换，将&nbsp;<code>"5"</code>&nbsp;用&nbsp;<code>"15"</code>&nbsp;替换并将&nbsp;<code>"1"</code>&nbsp;用&nbsp;<code>"11"</code>&nbsp;替换。因此压缩后字符串变为 <code>"23321511"</code>。</p>

<p>给定一个整数&nbsp;<code>n</code>&nbsp;，返回&nbsp;<strong>外观数列</strong>&nbsp;的第&nbsp;<code>n</code>&nbsp;个元素。</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>n = 4</p>

<p><strong>输出：</strong>"1211"</p>

<p><strong>解释：</strong></p>

<p>countAndSay(1) = "1"</p>

<p>countAndSay(2) = "1" 的行程长度编码 = "11"</p>

<p>countAndSay(3) = "11" 的行程长度编码 = "21"</p>

<p>countAndSay(4) = "21" 的行程长度编码 = "1211"</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 1</span></p>

<p><strong>输出：</strong><span class="example-io">"1"</span></p>

<p><strong>解释：</strong></p>

<p>这是基本情况。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>

<p>&nbsp;</p>
<strong>进阶：</strong>你能迭代解决该问题吗？

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
    def countAndSay(self, n: int) -> str:
        s = '1'
        for _ in range(n - 1):
            i = 0
            t = []
            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1
                t.append(str(j - i))
                t.append(str(s[i]))
                i = j
            s = ''.join(t)
        return s
```

#### Java

```java
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        while (--n > 0) {
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < s.length();) {
                int j = i;
                while (j < s.length() && s.charAt(j) == s.charAt(i)) {
                    ++j;
                }
                t.append((j - i) + "");
                t.append(s.charAt(i));
                i = j;
            }
            s = t.toString();
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string t = "";
            for (int i = 0; i < s.size();) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) ++j;
                t += to_string(j - i);
                t += s[i];
                i = j;
            }
            s = t;
        }
        return s;
    }
};
```

#### Go

```go
func countAndSay(n int) string {
	s := "1"
	for k := 0; k < n-1; k++ {
		t := &strings.Builder{}
		i := 0
		for i < len(s) {
			j := i
			for j < len(s) && s[j] == s[i] {
				j++
			}
			t.WriteString(strconv.Itoa(j - i))
			t.WriteByte(s[i])
			i = j
		}
		s = t.String()
	}
	return s
}
```

#### TypeScript

```ts
function countAndSay(n: number): string {
    let s = '1';
    for (let i = 1; i < n; i++) {
        let t = '';
        let cur = s[0];
        let count = 1;
        for (let j = 1; j < s.length; j++) {
            if (s[j] !== cur) {
                t += `${count}${cur}`;
                cur = s[j];
                count = 0;
            }
            count++;
        }
        t += `${count}${cur}`;
        s = t;
    }
    return s;
}
```

#### Rust

```rust
use std::iter::once;

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        (1..n)
            .fold(vec![1], |curr, _| {
                let mut next = vec![];
                let mut slow = 0;
                for fast in 0..=curr.len() {
                    if fast == curr.len() || curr[slow] != curr[fast] {
                        next.extend(once((fast - slow) as u8).chain(once(curr[slow])));
                        slow = fast;
                    }
                }
                next
            })
            .into_iter()
            .map(|digit| (digit + b'0') as char)
            .collect()
    }
}
```

#### JavaScript

```js
const countAndSay = function (n) {
    let s = '1';

    for (let i = 2; i <= n; i++) {
        let count = 1,
            str = '',
            len = s.length;

        for (let j = 0; j < len; j++) {
            if (j < len - 1 && s[j] === s[j + 1]) {
                count++;
            } else {
                str += `${count}${s[j]}`;
                count = 1;
            }
        }
        s = str;
    }
    return s;
};
```

#### C#

```cs
using System.Text;
public class Solution {
    public string CountAndSay(int n) {
        var s = "1";
        while (n > 1)
        {
            var sb = new StringBuilder();
            var lastChar = '1';
            var count = 0;
            foreach (var ch in s)
            {
                if (count > 0 && lastChar == ch)
                {
                    ++count;
                }
                else
                {
                    if (count > 0)
                    {
                        sb.Append(count);
                        sb.Append(lastChar);
                    }
                    lastChar = ch;
                    count = 1;
                }
            }
            if (count > 0)
            {
                sb.Append(count);
                sb.Append(lastChar);
            }
            s = sb.ToString();
            --n;
        }
        return s;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer $n
     * @return string
     */

    function countAndSay($n) {
        if ($n <= 0) {
            return '';
        }

        $result = '1';
        for ($i = 2; $i <= $n; $i++) {
            $count = 1;
            $say = '';
            for ($j = 1; $j < strlen($result); $j++) {
                if ($result[$j] == $result[$j - 1]) {
                    $count++;
                } else {
                    $say .= $count . $result[$j - 1];
                    $count = 1;
                }
            }
            $say .= $count . $result[strlen($result) - 1];
            $result = $say;
        }
        return $result;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [39. 组合总和](https://leetcode.cn/problems/combination-sum){#39}

{{< tabs "39" >}}

{{% tab "python" %}}
```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            dfs(i + 1, s)
            t.append(candidates[i])
            dfs(i, s - candidates[i])
            t.pop()

        candidates.sort()
        t = []
        ans = []
        dfs(0, target)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.add(candidates[i]);
        dfs(i, s - candidates[i]);
        t.remove(t.size() - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            dfs(i + 1, s);
            t.push_back(candidates[i]);
            dfs(i, s - candidates[i]);
            t.pop_back();
        };
        dfs(0, target);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func combinationSum(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if i >= len(candidates) || s < candidates[i] {
			return
		}
		dfs(i+1, s)
		t = append(t, candidates[i])
		dfs(i, s-candidates[i])
		t = t[:len(t)-1]
	}
	dfs(0, target)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function combinationSum(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.push(candidates[i]);
        dfs(i, s - candidates[i]);
        t.pop();
    };
    dfs(0, target);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        Self::dfs(i + 1, s, candidates, t, ans);
        t.push(candidates[i]);
        Self::dfs(i, s - candidates[i], candidates, t, ans);
        t.pop();
    }

    pub fn combination_sum(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (i >= candidates.Length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.Add(candidates[i]);
        dfs(i, s - candidates[i]);
        t.RemoveAt(t.Count - 1);
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer[] $candidates
     * @param integer $target
     * @return integer[][]
     */

    function combinationSum($candidates, $target) {
        $result = [];
        $currentCombination = [];
        $startIndex = 0;

        sort($candidates);
        $this->findCombinations($candidates, $target, $startIndex, $currentCombination, $result);
        return $result;
    }

    function findCombinations($candidates, $target, $startIndex, $currentCombination, &$result) {
        if ($target === 0) {
            $result[] = $currentCombination;
            return;
        }

        for ($i = $startIndex; $i < count($candidates); $i++) {
            $num = $candidates[$i];
            if ($num > $target) {
                break;
            }
            $currentCombination[] = $num;

            $this->findCombinations($candidates, $target - $num, $i, $currentCombination, $result);
            array_pop($currentCombination);
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

<p>给你一个 <strong>无重复元素</strong> 的整数数组&nbsp;<code>candidates</code> 和一个目标整数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中可以使数字和为目标数&nbsp;<code>target</code> 的 所有<em>&nbsp;</em><strong>不同组合</strong> ，并以列表形式返回。你可以按 <strong>任意顺序</strong> 返回这些组合。</p>

<p><code>candidates</code> 中的 <strong>同一个</strong> 数字可以 <strong>无限制重复被选取</strong> 。如果至少一个数字的被选数量不同，则两种组合是不同的。&nbsp;</p>

<p>对于给定的输入，保证和为&nbsp;<code>target</code> 的不同组合数少于 <code>150</code> 个。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>candidates = <code>[2,3,6,7]</code>, target = <code>7</code>
<strong>输出：</strong>[[2,2,3],[7]]
<strong>解释：</strong>
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入: </strong>candidates = [2,3,5]<code>, </code>target = 8
<strong>输出: </strong>[[2,2,2,2],[2,3,3],[3,5]]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[2], </code>target = 1
<strong>输出: </strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>2 &lt;= candidates[i] &lt;= 40</code></li>
	<li><code>candidates</code> 的所有元素 <strong>互不相同</strong></li>
	<li><code>1 &lt;= target &lt;= 40</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 剪枝 + 回溯

我们可以先对数组进行排序，方便剪枝。

接下来，我们设计一个函数 $dfs(i, s)$，表示从下标 $i$ 开始搜索，且剩余目标值为 $s$，其中 $i$ 和 $s$ 都是非负整数，当前搜索路径为 $t$，答案为 $ans$。

在函数 $dfs(i, s)$ 中，我们先判断 $s$ 是否为 $0$，如果是，则将当前搜索路径 $t$ 加入答案 $ans$ 中，然后返回。如果 $s \lt candidates[i]$，说明当前下标及后面的下标的元素都大于剩余目标值 $s$，路径不合法，直接返回。否则，我们从下标 $i$ 开始搜索，搜索的下标范围是 $j \in [i, n)$，其中 $n$ 为数组 $candidates$ 的长度。在搜索的过程中，我们将当前下标的元素加入搜索路径 $t$，递归调用函数 $dfs(j, s - candidates[j])$，递归结束后，将当前下标的元素从搜索路径 $t$ 中移除。

在主函数中，我们只要调用函数 $dfs(0, target)$，即可得到答案。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $candidates$ 的长度。由于剪枝，实际的时间复杂度要远小于 $O(2^n \times n)$。

相似题目：

-   [40. 组合总和 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0040.Combination%20Sum%20II/README.md)
-   [77. 组合](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0077.Combinations/README.md)
-   [216. 组合总和 III](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0216.Combination%20Sum%20III/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                t.append(candidates[j])
                dfs(j, s - candidates[j])
                t.pop()

        candidates.sort()
        t = []
        ans = []
        dfs(0, target)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList(t));
            return;
        }
        if (s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            t.add(candidates[j]);
            dfs(j, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                t.push_back(candidates[j]);
                dfs(j, s - candidates[j]);
                t.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```

#### Go

```go
func combinationSum(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if s < candidates[i] {
			return
		}
		for j := i; j < len(candidates); j++ {
			t = append(t, candidates[j])
			dfs(j, s-candidates[j])
			t = t[:len(t)-1]
		}
	}
	dfs(0, target)
	return
}
```

#### TypeScript

```ts
function combinationSum(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (s < candidates[i]) {
            return;
        }
        for (let j = i; j < candidates.length; ++j) {
            t.push(candidates[j]);
            dfs(j, s - candidates[j]);
            t.pop();
        }
    };
    dfs(0, target);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if s < candidates[i] {
            return;
        }
        for j in i..candidates.len() {
            t.push(candidates[j]);
            Self::dfs(j, s - candidates[j], candidates, t, ans);
            t.pop();
        }
    }

    pub fn combination_sum(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.Length; ++j) {
            t.Add(candidates[j]);
            dfs(j, s - candidates[j]);
            t.RemoveAt(t.Count - 1);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 剪枝 + 回溯（写法二）

我们也可以将函数 $dfs(i, s)$ 的实现逻辑改为另一种写法。在函数 $dfs(i, s)$ 中，我们先判断 $s$ 是否为 $0$，如果是，则将当前搜索路径 $t$ 加入答案 $ans$ 中，然后返回。如果 $i \geq n$ 或者 $s \lt candidates[i]$，路径不合法，直接返回。否则，我们考虑两种情况，一种是不选当前下标的元素，即递归调用函数 $dfs(i + 1, s)$，另一种是选当前下标的元素，即递归调用函数 $dfs(i, s - candidates[i])$。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $candidates$ 的长度。由于剪枝，实际的时间复杂度要远小于 $O(2^n \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            dfs(i + 1, s)
            t.append(candidates[i])
            dfs(i, s - candidates[i])
            t.pop()

        candidates.sort()
        t = []
        ans = []
        dfs(0, target)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.add(candidates[i]);
        dfs(i, s - candidates[i]);
        t.remove(t.size() - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            dfs(i + 1, s);
            t.push_back(candidates[i]);
            dfs(i, s - candidates[i]);
            t.pop_back();
        };
        dfs(0, target);
        return ans;
    }
};
```

#### Go

```go
func combinationSum(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if i >= len(candidates) || s < candidates[i] {
			return
		}
		dfs(i+1, s)
		t = append(t, candidates[i])
		dfs(i, s-candidates[i])
		t = t[:len(t)-1]
	}
	dfs(0, target)
	return
}
```

#### TypeScript

```ts
function combinationSum(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.push(candidates[i]);
        dfs(i, s - candidates[i]);
        t.pop();
    };
    dfs(0, target);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        Self::dfs(i + 1, s, candidates, t, ans);
        t.push(candidates[i]);
        Self::dfs(i, s - candidates[i], candidates, t, ans);
        t.pop();
    }

    pub fn combination_sum(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (i >= candidates.Length || s < candidates[i]) {
            return;
        }
        dfs(i + 1, s);
        t.Add(candidates[i]);
        dfs(i, s - candidates[i]);
        t.RemoveAt(t.Count - 1);
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer[] $candidates
     * @param integer $target
     * @return integer[][]
     */

    function combinationSum($candidates, $target) {
        $result = [];
        $currentCombination = [];
        $startIndex = 0;

        sort($candidates);
        $this->findCombinations($candidates, $target, $startIndex, $currentCombination, $result);
        return $result;
    }

    function findCombinations($candidates, $target, $startIndex, $currentCombination, &$result) {
        if ($target === 0) {
            $result[] = $currentCombination;
            return;
        }

        for ($i = $startIndex; $i < count($candidates); $i++) {
            $num = $candidates[$i];
            if ($num > $target) {
                break;
            }
            $currentCombination[] = $num;

            $this->findCombinations($candidates, $target - $num, $i, $currentCombination, $result);
            array_pop($currentCombination);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [40. 组合总和 II](https://leetcode.cn/problems/combination-sum-ii){#40}

{{< tabs "40" >}}

{{% tab "python" %}}
```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            x = candidates[i]
            t.append(x)
            dfs(i + 1, s - x)
            t.pop()
            while i < len(candidates) and candidates[i] == x:
                i += 1
            dfs(i, s)

        candidates.sort()
        ans = []
        t = []
        dfs(0, target)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        int x = candidates[i];
        t.add(x);
        dfs(i + 1, s - x);
        t.remove(t.size() - 1);
        while (i < candidates.length && candidates[i] == x) {
            ++i;
        }
        dfs(i, s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            int x = candidates[i];
            t.emplace_back(x);
            dfs(i + 1, s - x);
            t.pop_back();
            while (i < candidates.size() && candidates[i] == x) {
                ++i;
            }
            dfs(i, s);
        };
        dfs(0, target);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func combinationSum2(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if i >= len(candidates) || s < candidates[i] {
			return
		}
		for j := i; j < len(candidates); j++ {
			if j > i && candidates[j] == candidates[j-1] {
				continue
			}
			t = append(t, candidates[j])
			dfs(j+1, s-candidates[j])
			t = t[:len(t)-1]
		}
	}
	dfs(0, target)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function combinationSum2(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        const x = candidates[i];
        t.push(x);
        dfs(i + 1, s - x);
        t.pop();
        while (i < candidates.length && candidates[i] === x) {
            ++i;
        }
        dfs(i, s);
    };
    dfs(0, target);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(mut i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        let x = candidates[i];
        t.push(x);
        Self::dfs(i + 1, s - x, candidates, t, ans);
        t.pop();
        while i < candidates.len() && candidates[i] == x {
            i += 1;
        }
        Self::dfs(i, s, candidates, t, ans);
    }

    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
    candidates.sort((a, b) => a - b);
    const ans = [];
    const t = [];
    const dfs = (i, s) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        const x = candidates[i];
        t.push(x);
        dfs(i + 1, s - x);
        t.pop();
        while (i < candidates.length && candidates[i] === x) {
            ++i;
        }
        dfs(i, s);
    };
    dfs(0, target);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (i >= candidates.Length || s < candidates[i]) {
            return;
        }
        int x = candidates[i];
        t.Add(x);
        dfs(i + 1, s - x);
        t.RemoveAt(t.Count - 1);
        while (i < candidates.Length && candidates[i] == x) {
            ++i;
        }
        dfs(i, s);
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer[] $candidates
     * @param integer $target
     * @return integer[][]
     */

    function combinationSum2($candidates, $target) {
        $result = [];
        $currentCombination = [];
        $startIndex = 0;

        sort($candidates);
        $this->findCombinations($candidates, $target, $startIndex, $currentCombination, $result);
        return $result;
    }

    function findCombinations($candidates, $target, $startIndex, $currentCombination, &$result) {
        if ($target === 0) {
            $result[] = $currentCombination;
            return;
        }

        for ($i = $startIndex; $i < count($candidates); $i++) {
            $num = $candidates[$i];
            if ($num > $target) {
                break;
            }

            if ($i > $startIndex && $candidates[$i] === $candidates[$i - 1]) {
                continue;
            }
            $currentCombination[] = $num;

            $this->findCombinations(
                $candidates,
                $target - $num,
                $i + 1,
                $currentCombination,
                $result,
            );
            array_pop($currentCombination);
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

<p>给定一个候选人编号的集合&nbsp;<code>candidates</code>&nbsp;和一个目标数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中所有可以使数字和为&nbsp;<code>target</code>&nbsp;的组合。</p>

<p><code>candidates</code>&nbsp;中的每个数字在每个组合中只能使用&nbsp;<strong>一次</strong>&nbsp;。</p>

<p><strong>注意：</strong>解集不能包含重复的组合。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> candidates =&nbsp;<code>[10,1,2,7,6,1,5]</code>, target =&nbsp;<code>8</code>,
<strong>输出:</strong>
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,
<strong>输出:</strong>
[
[1,2,2],
[5]
]</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 剪枝 + 回溯

我们可以先对数组进行排序，方便剪枝以及跳过重复的数字。

接下来，我们设计一个函数 $dfs(i, s)$，表示从下标 $i$ 开始搜索，且剩余目标值为 $s$，其中 $i$ 和 $s$ 都是非负整数，当前搜索路径为 $t$，答案为 $ans$。

在函数 $dfs(i, s)$ 中，我们先判断 $s$ 是否为 $0$，如果是，则将当前搜索路径 $t$ 加入答案 $ans$ 中，然后返回。如果 $i \geq n$，或者 $s \lt candidates[i]$，说明当前路径不合法，直接返回。否则，我们从下标 $i$ 开始搜索，搜索的下标范围是 $j \in [i, n)$，其中 $n$ 为数组 $candidates$ 的长度。在搜索的过程中，如果 $j \gt i$ 并且 $candidates[j] = candidates[j - 1]$，说明当前数字与上一个数字相同，我们可以跳过当前数字，因为上一个数字已经搜索过了。否则，我们将当前数字加入搜索路径 $t$ 中，然后递归调用函数 $dfs(j + 1, s - candidates[j])$，然后将当前数字从搜索路径 $t$ 中移除。

在主函数中，我们只要调用函数 $dfs(0, target)$，即可得到答案。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $candidates$ 的长度。由于剪枝，实际的时间复杂度要远小于 $O(2^n \times n)$。

相似题目：

-   [39. 组合总和](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0039.Combination%20Sum/README.md)
-   [77. 组合](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0077.Combinations/README.md)
-   [216. 组合总和 III](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0216.Combination%20Sum%20III/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                t.append(candidates[j])
                dfs(j + 1, s - candidates[j])
                t.pop()

        candidates.sort()
        ans = []
        t = []
        dfs(0, target)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            t.add(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                t.emplace_back(candidates[j]);
                dfs(j + 1, s - candidates[j]);
                t.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```

#### Go

```go
func combinationSum2(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if i >= len(candidates) || s < candidates[i] {
			return
		}
		for j := i; j < len(candidates); j++ {
			if j > i && candidates[j] == candidates[j-1] {
				continue
			}
			t = append(t, candidates[j])
			dfs(j+1, s-candidates[j])
			t = t[:len(t)-1]
		}
	}
	dfs(0, target)
	return
}
```

#### TypeScript

```ts
function combinationSum2(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        for (let j = i; j < candidates.length; j++) {
            if (j > i && candidates[j] === candidates[j - 1]) {
                continue;
            }
            t.push(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.pop();
        }
    };
    dfs(0, target);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        for j in i..candidates.len() {
            if j > i && candidates[j] == candidates[j - 1] {
                continue;
            }
            t.push(candidates[j]);
            Self::dfs(j + 1, s - candidates[j], candidates, t, ans);
            t.pop();
        }
    }

    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
    candidates.sort((a, b) => a - b);
    const ans = [];
    const t = [];
    const dfs = (i, s) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        for (let j = i; j < candidates.length; ++j) {
            if (j > i && candidates[j] === candidates[j - 1]) {
                continue;
            }
            t.push(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.pop();
        }
    };
    dfs(0, target);
    return ans;
};
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (i >= candidates.Length || s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.Length; ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            t.Add(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.RemoveAt(t.Count - 1);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 剪枝 + 回溯（写法二）

我们也可以将函数 $dfs(i, s)$ 的实现逻辑改为另一种写法。如果我们选择当前数字，那么我们将当前数字加入搜索路径 $t$ 中，然后递归调用函数 $dfs(i + 1, s - candidates[i])$，然后将当前数字从搜索路径 $t$ 中移除。如果我们不选择当前数字，那么我们可以跳过与当前数字相同的所有数字，然后递归调用函数 $dfs(j, s)$，其中 $j$ 为第一个与当前数字不同的数字的下标。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $candidates$ 的长度。由于剪枝，实际的时间复杂度要远小于 $O(2^n \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            x = candidates[i]
            t.append(x)
            dfs(i + 1, s - x)
            t.pop()
            while i < len(candidates) and candidates[i] == x:
                i += 1
            dfs(i, s)

        candidates.sort()
        ans = []
        t = []
        dfs(0, target)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        int x = candidates[i];
        t.add(x);
        dfs(i + 1, s - x);
        t.remove(t.size() - 1);
        while (i < candidates.length && candidates[i] == x) {
            ++i;
        }
        dfs(i, s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            int x = candidates[i];
            t.emplace_back(x);
            dfs(i + 1, s - x);
            t.pop_back();
            while (i < candidates.size() && candidates[i] == x) {
                ++i;
            }
            dfs(i, s);
        };
        dfs(0, target);
        return ans;
    }
};
```

#### Go

```go
func combinationSum2(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			ans = append(ans, slices.Clone(t))
			return
		}
		if i >= len(candidates) || s < candidates[i] {
			return
		}
		for j := i; j < len(candidates); j++ {
			if j > i && candidates[j] == candidates[j-1] {
				continue
			}
			t = append(t, candidates[j])
			dfs(j+1, s-candidates[j])
			t = t[:len(t)-1]
		}
	}
	dfs(0, target)
	return
}
```

#### TypeScript

```ts
function combinationSum2(candidates: number[], target: number): number[][] {
    candidates.sort((a, b) => a - b);
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        const x = candidates[i];
        t.push(x);
        dfs(i + 1, s - x);
        t.pop();
        while (i < candidates.length && candidates[i] === x) {
            ++i;
        }
        dfs(i, s);
    };
    dfs(0, target);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(mut i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        let x = candidates[i];
        t.push(x);
        Self::dfs(i + 1, s - x, candidates, t, ans);
        t.pop();
        while i < candidates.len() && candidates[i] == x {
            i += 1;
        }
        Self::dfs(i, s, candidates, t, ans);
    }

    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
    candidates.sort((a, b) => a - b);
    const ans = [];
    const t = [];
    const dfs = (i, s) => {
        if (s === 0) {
            ans.push(t.slice());
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        const x = candidates[i];
        t.push(x);
        dfs(i + 1, s - x);
        t.pop();
        while (i < candidates.length && candidates[i] === x) {
            ++i;
        }
        dfs(i, s);
    };
    dfs(0, target);
    return ans;
};
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] candidates;

    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.Add(new List<int>(t));
            return;
        }
        if (i >= candidates.Length || s < candidates[i]) {
            return;
        }
        int x = candidates[i];
        t.Add(x);
        dfs(i + 1, s - x);
        t.RemoveAt(t.Count - 1);
        while (i < candidates.Length && candidates[i] == x) {
            ++i;
        }
        dfs(i, s);
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer[] $candidates
     * @param integer $target
     * @return integer[][]
     */

    function combinationSum2($candidates, $target) {
        $result = [];
        $currentCombination = [];
        $startIndex = 0;

        sort($candidates);
        $this->findCombinations($candidates, $target, $startIndex, $currentCombination, $result);
        return $result;
    }

    function findCombinations($candidates, $target, $startIndex, $currentCombination, &$result) {
        if ($target === 0) {
            $result[] = $currentCombination;
            return;
        }

        for ($i = $startIndex; $i < count($candidates); $i++) {
            $num = $candidates[$i];
            if ($num > $target) {
                break;
            }

            if ($i > $startIndex && $candidates[$i] === $candidates[$i - 1]) {
                continue;
            }
            $currentCombination[] = $num;

            $this->findCombinations(
                $candidates,
                $target - $num,
                $i + 1,
                $currentCombination,
                $result,
            );
            array_pop($currentCombination);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
