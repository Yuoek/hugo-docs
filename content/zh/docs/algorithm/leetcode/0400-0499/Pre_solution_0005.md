---
title: "0440_字典序的第K小数字"
date: 2025-10-08T18:36:10+08:00
weight: 5
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 双指针, 哈希表, 图, 字典树, 字符串, 广度优先搜索, 拓扑排序, 数学, 数组, 栈, 树, 深度优先搜索, 设计, 链表]
---

{{< markmap >}}
### [0440_字典序的第K小数字](#440)
#### [字典树](#440)
### [0441_排列硬币](#441)
#### [数学](#441)
#### [二分查找](#441)
### [0442_数组中重复的数据](#442)
#### [数组](#442)
#### [哈希表](#442)
### [0443_压缩字符串](#443)
#### [双指针](#443)
#### [字符串](#443)
### [0444_序列重建 🔒](#444)
#### [图](#444)
#### [拓扑排序](#444)
#### [数组](#444)
### [0445_两数相加 II](#445)
#### [栈](#445)
#### [链表](#445)
#### [数学](#445)
### [0446_等差数列划分 II - 子序列](#446)
#### [数组](#446)
#### [动态规划](#446)
### [0447_回旋镖的数量](#447)
#### [数组](#447)
#### [哈希表](#447)
#### [数学](#447)
### [0448_找到所有数组中消失的数字](#448)
#### [数组](#448)
#### [哈希表](#448)
### [0449_序列化和反序列化二叉搜索树](#449)
#### [树](#449)
#### [深度优先搜索](#449)
#### [广度优先搜索](#449)
#### [设计](#449)
#### [二叉搜索树](#449)
#### [字符串](#449)
#### [二叉树](#449)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0440_字典序的第K小数字
___
#### 字典树
---
### 0441_排列硬币
___
#### 数学
___
#### 二分查找
---
### 0442_数组中重复的数据
___
#### 数组
___
#### 哈希表
---
### 0443_压缩字符串
___
#### 双指针
___
#### 字符串
---
### 0444_序列重建 🔒
___
#### 图
___
#### 拓扑排序
___
#### 数组
---
### 0445_两数相加 II
___
#### 栈
___
#### 链表
___
#### 数学
---
### 0446_等差数列划分 II - 子序列
___
#### 数组
___
#### 动态规划
---
### 0447_回旋镖的数量
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 0448_找到所有数组中消失的数字
___
#### 数组
___
#### 哈希表
---
### 0449_序列化和反序列化二叉搜索树
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 二叉搜索树
___
#### 字符串
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 字典树 | 字符串 |
| 广度优先搜索 | 拓扑排序 | 数学 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 设计 | 链表 |

# [440. 字典序的第K小数字](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order){#440}

{{< tabs "440" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def count(curr):
            next, cnt = curr + 1, 0
            while curr <= n:
                cnt += min(n - curr + 1, next - curr)
                next, curr = next * 10, curr * 10
            return cnt

        curr = 1
        k -= 1
        while k:
            cnt = count(curr)
            if k >= cnt:
                k -= cnt
                curr += 1
            else:
                k -= 1
                curr *= 10
        return curr
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int findKthNumber(int n, int k) {
        this.n = n;
        long curr = 1;
        --k;
        while (k > 0) {
            int cnt = count(curr);
            if (k >= cnt) {
                k -= cnt;
                ++curr;
            } else {
                --k;
                curr *= 10;
            }
        }
        return (int) curr;
    }

    public int count(long curr) {
        long next = curr + 1;
        long cnt = 0;
        while (curr <= n) {
            cnt += Math.min(n - curr + 1, next - curr);
            next *= 10;
            curr *= 10;
        }
        return (int) cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int n;

    int findKthNumber(int n, int k) {
        this->n = n;
        --k;
        long long curr = 1;
        while (k) {
            int cnt = count(curr);
            if (k >= cnt) {
                k -= cnt;
                ++curr;
            } else {
                --k;
                curr *= 10;
            }
        }
        return (int) curr;
    }

    int count(long long curr) {
        long long next = curr + 1;
        int cnt = 0;
        while (curr <= n) {
            cnt += min(n - curr + 1, next - curr);
            next *= 10;
            curr *= 10;
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthNumber(n int, k int) int {
	count := func(curr int) int {
		next := curr + 1
		cnt := 0
		for curr <= n {
			cnt += min(n-curr+1, next-curr)
			next *= 10
			curr *= 10
		}
		return cnt
	}
	curr := 1
	k--
	for k > 0 {
		cnt := count(curr)
		if k >= cnt {
			k -= cnt
			curr++
		} else {
			k--
			curr *= 10
		}
	}
	return curr
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKthNumber(n: number, k: number): number {
    function count(curr: number): number {
        let next = curr + 1;
        let cnt = 0;
        while (curr <= n) {
            cnt += Math.min(n - curr + 1, next - curr);
            curr *= 10;
            next *= 10;
        }
        return cnt;
    }

    let curr = 1;
    k--;

    while (k > 0) {
        const cnt = count(curr);
        if (k >= cnt) {
            k -= cnt;
            curr += 1;
        } else {
            k -= 1;
            curr *= 10;
        }
    }

    return curr;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_kth_number(n: i32, k: i32) -> i32 {
        fn count(mut curr: i64, n: i32) -> i32 {
            let mut next = curr + 1;
            let mut total = 0;
            let n = n as i64;
            while curr <= n {
                total += std::cmp::min(n - curr + 1, next - curr);
                curr *= 10;
                next *= 10;
            }
            total as i32
        }

        let mut curr = 1;
        let mut k = k - 1;

        while k > 0 {
            let cnt = count(curr as i64, n);
            if k >= cnt {
                k -= cnt;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }

        curr
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定整数&nbsp;<code>n</code>&nbsp;和&nbsp;<code>k</code>，返回&nbsp;&nbsp;<code>[1, n]</code>&nbsp;中字典序第&nbsp;<code>k</code>&nbsp;小的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>n = 13, k = 2
<strong>输出: </strong>10
<strong>解释: </strong>字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 1, k = 1
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树计数 + 贪心构造

本题要求在区间 $[1, n]$ 中，按**字典序**排序后，找到第 $k$ 小的数字。由于 $n$ 的范围非常大（最多可达 $10^9$），我们无法直接枚举所有数字后排序。因此我们采用**贪心 + 字典树模拟**的策略。

我们将 $[1, n]$ 看作一棵 **十叉字典树（Trie）**：

-   每个节点是一个前缀，根节点为空串；
-   节点的子节点是当前前缀拼接上 $0 \sim 9$；
-   例如前缀 $1$ 会有子节点 $10, 11, \ldots, 19$，而 $10$ 会有 $100, 101, \ldots, 109$；
-   这种结构天然符合字典序遍历。

```
根
├── 1
│   ├── 10
│   ├── 11
│   ├── ...
├── 2
├── ...
```

我们使用变量 $\textit{curr}$ 表示当前前缀，初始为 $1$。每次我们尝试向下扩展前缀，直到找到第 $k$ 小的数字。

每次我们计算当前前缀下有多少个合法数字（即以 $\textit{curr}$ 为前缀、且不超过 $n$ 的整数个数），记作 $\textit{count}(\text{curr})$：

-   如果 $k \ge \text{count}(\text{curr})$：说明目标不在这棵子树中，跳过整棵子树，前缀右移：$\textit{curr} \leftarrow \text{curr} + 1$，并更新 $k \leftarrow k - \text{count}(\text{curr})$；
-   否则：说明目标在当前前缀的子树中，进入下一层：$\textit{curr} \leftarrow \text{curr} \times 10$，并消耗一个前缀：$k \leftarrow k - 1$。

每一层我们将当前区间扩大 $10$ 倍，向下延伸到更长的前缀，直到超出 $n$。

时间复杂度 $O(\log^2 n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def count(curr):
            next, cnt = curr + 1, 0
            while curr <= n:
                cnt += min(n - curr + 1, next - curr)
                next, curr = next * 10, curr * 10
            return cnt

        curr = 1
        k -= 1
        while k:
            cnt = count(curr)
            if k >= cnt:
                k -= cnt
                curr += 1
            else:
                k -= 1
                curr *= 10
        return curr
```

#### Java

```java
class Solution {
    private int n;

    public int findKthNumber(int n, int k) {
        this.n = n;
        long curr = 1;
        --k;
        while (k > 0) {
            int cnt = count(curr);
            if (k >= cnt) {
                k -= cnt;
                ++curr;
            } else {
                --k;
                curr *= 10;
            }
        }
        return (int) curr;
    }

    public int count(long curr) {
        long next = curr + 1;
        long cnt = 0;
        while (curr <= n) {
            cnt += Math.min(n - curr + 1, next - curr);
            next *= 10;
            curr *= 10;
        }
        return (int) cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int n;

    int findKthNumber(int n, int k) {
        this->n = n;
        --k;
        long long curr = 1;
        while (k) {
            int cnt = count(curr);
            if (k >= cnt) {
                k -= cnt;
                ++curr;
            } else {
                --k;
                curr *= 10;
            }
        }
        return (int) curr;
    }

    int count(long long curr) {
        long long next = curr + 1;
        int cnt = 0;
        while (curr <= n) {
            cnt += min(n - curr + 1, next - curr);
            next *= 10;
            curr *= 10;
        }
        return cnt;
    }
};
```

#### Go

```go
func findKthNumber(n int, k int) int {
	count := func(curr int) int {
		next := curr + 1
		cnt := 0
		for curr <= n {
			cnt += min(n-curr+1, next-curr)
			next *= 10
			curr *= 10
		}
		return cnt
	}
	curr := 1
	k--
	for k > 0 {
		cnt := count(curr)
		if k >= cnt {
			k -= cnt
			curr++
		} else {
			k--
			curr *= 10
		}
	}
	return curr
}
```

#### TypeScript

```ts
function findKthNumber(n: number, k: number): number {
    function count(curr: number): number {
        let next = curr + 1;
        let cnt = 0;
        while (curr <= n) {
            cnt += Math.min(n - curr + 1, next - curr);
            curr *= 10;
            next *= 10;
        }
        return cnt;
    }

    let curr = 1;
    k--;

    while (k > 0) {
        const cnt = count(curr);
        if (k >= cnt) {
            k -= cnt;
            curr += 1;
        } else {
            k -= 1;
            curr *= 10;
        }
    }

    return curr;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_kth_number(n: i32, k: i32) -> i32 {
        fn count(mut curr: i64, n: i32) -> i32 {
            let mut next = curr + 1;
            let mut total = 0;
            let n = n as i64;
            while curr <= n {
                total += std::cmp::min(n - curr + 1, next - curr);
                curr *= 10;
                next *= 10;
            }
            total as i32
        }

        let mut curr = 1;
        let mut k = k - 1;

        while k > 0 {
            let cnt = count(curr as i64, n);
            if k >= cnt {
                k -= cnt;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }

        curr
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [441. 排列硬币](https://leetcode.cn/problems/arranging-coins){#441}

{{< tabs "441" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        while left < right:
            mid = (left + right + 1) >> 1
            if (1 + mid) * mid // 2 <= n:
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arrangeCoins(int n) {
        long left = 1, right = n;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if ((1 + mid) * mid / 2 <= n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int) left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using LL = long;

class Solution {
public:
    int arrangeCoins(int n) {
        LL left = 1, right = n;
        while (left < right) {
            LL mid = left + right + 1 >> 1;
            LL s = (1 + mid) * mid >> 1;
            if (n < s)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrangeCoins(n int) int {
	left, right := 1, n
	for left < right {
		mid := (left + right + 1) >> 1
		if (1+mid)*mid/2 <= n {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你总共有&nbsp;<code>n</code><em>&nbsp;</em>枚硬币，并计划将它们按阶梯状排列。对于一个由 <code>k</code> 行组成的阶梯，其第 <code>i</code><em> </em>行必须正好有 <code>i</code><em> </em>枚硬币。阶梯的最后一行 <strong>可能</strong> 是不完整的。</p>

<p>给你一个数字&nbsp;<code>n</code><em> </em>，计算并返回可形成 <strong>完整阶梯行</strong> 的总行数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0441.Arranging%20Coins/images/arrangecoins1-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>2
<strong>解释：</strong>因为第三行不完整，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0441.Arranging%20Coins/images/arrangecoins2-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>3
<strong>解释：</strong>因为第四行不完整，所以返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学推导

`(1 + x) * x / 2 <= n`，求解 x。

`(x + 1/2)² <= 2n + 1/4`，即 `x <= sqrt(2n + 1/4) - 1/2`。

由于 2n 可能溢出，故转换为 `x <= sqrt(2) * sqrt(n + 1/8) - 1/2`。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int(math.sqrt(2) * math.sqrt(n + 0.125) - 0.5)
```

#### Java

```java
class Solution {
    public int arrangeCoins(int n) {
        return (int) (Math.sqrt(2) * Math.sqrt(n + 0.125) - 0.5);
    }
}
```

#### C++

```cpp
using LL = long;

class Solution {
public:
    int arrangeCoins(int n) {
        LL left = 1, right = n;
        while (left < right) {
            LL mid = left + right + 1 >> 1;
            LL s = (1 + mid) * mid >> 1;
            if (n < s)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
```

#### Go

```go
func arrangeCoins(n int) int {
	left, right := 1, n
	for left < right {
		mid := (left + right + 1) >> 1
		if (1+mid)*mid/2 <= n {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        while left < right:
            mid = (left + right + 1) >> 1
            if (1 + mid) * mid // 2 <= n:
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    public int arrangeCoins(int n) {
        long left = 1, right = n;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if ((1 + mid) * mid / 2 <= n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int) left;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [442. 数组中重复的数据](https://leetcode.cn/problems/find-all-duplicates-in-an-array){#442}

{{< tabs "442" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            while nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        return [v for i, v in enumerate(nums) if v != i + 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.add(nums[i]);
            }
        }
        return ans;
    }

    void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDuplicates(nums []int) []int {
	for i := range nums {
		for nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	var ans []int
	for i, v := range nums {
		if v != i+1 {
			ans = append(ans, v)
		}
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，其中 <code>nums</code> 的所有整数都在范围 <code>[1, n]</code> 内，且每个整数出现 <strong>最多</strong><strong>两次</strong> 。请你找出所有出现 <strong>两次</strong> 的整数，并以数组形式返回。</p>

<p>你必须设计并实现一个时间复杂度为 <code>O(n)</code> 且仅使用常量额外空间（不包括存储输出所需的空间）的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,2,7,8,2,3,1]
<strong>输出：</strong>[2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 中的每个元素出现 <strong>一次</strong> 或 <strong>两次</strong></li>
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
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            while nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        return [v for i, v in enumerate(nums) if v != i + 1]
```

#### Java

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.add(nums[i]);
            }
        }
        return ans;
    }

    void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findDuplicates(nums []int) []int {
	for i := range nums {
		for nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	var ans []int
	for i, v := range nums {
		if v != i+1 {
			ans = append(ans, v)
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [443. 压缩字符串](https://leetcode.cn/problems/string-compression){#443}

{{< tabs "443" >}}

{{% tab "python" %}}
```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        i, k, n = 0, 0, len(chars)
        while i < n:
            j = i + 1
            while j < n and chars[j] == chars[i]:
                j += 1
            chars[k] = chars[i]
            k += 1
            if j - i > 1:
                cnt = str(j - i)
                for c in cnt:
                    chars[k] = c
                    k += 1
            i = j
        return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int compress(char[] chars) {
        int k = 0, n = chars.length;
        for (int i = 0, j = i + 1; i < n;) {
            while (j < n && chars[j] == chars[i]) {
                ++j;
            }
            chars[k++] = chars[i];
            if (j - i > 1) {
                String cnt = String.valueOf(j - i);
                for (char c : cnt.toCharArray()) {
                    chars[k++] = c;
                }
            }
            i = j;
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0, n = chars.size();
        for (int i = 0, j = i + 1; i < n;) {
            while (j < n && chars[j] == chars[i])
                ++j;
            chars[k++] = chars[i];
            if (j - i > 1) {
                for (char c : to_string(j - i)) {
                    chars[k++] = c;
                }
            }
            i = j;
        }
        return k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func compress(chars []byte) int {
	i, k, n := 0, 0, len(chars)
	for i < n {
		j := i + 1
		for j < n && chars[j] == chars[i] {
			j++
		}
		chars[k] = chars[i]
		k++
		if j-i > 1 {
			cnt := strconv.Itoa(j - i)
			for _, c := range cnt {
				chars[k] = byte(c)
				k++
			}
		}
		i = j
	}
	return k
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let (mut i, mut k, n) = (0, 0, chars.len());
        while i < n {
            let mut j = i + 1;
            while j < n && chars[j] == chars[i] {
                j += 1;
            }
            chars[k] = chars[i];
            k += 1;

            if j - i > 1 {
                let cnt = (j - i).to_string();
                for c in cnt.chars() {
                    chars[k] = c;
                    k += 1;
                }
            }
            i = j;
        }
        k as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符数组 <code>chars</code> ，请使用下述算法压缩：</p>

<p>从一个空字符串 <code>s</code> 开始。对于 <code>chars</code> 中的每组 <strong>连续重复字符</strong> ：</p>

<ul>
	<li>如果这一组长度为 <code>1</code> ，则将字符追加到 <code>s</code> 中。</li>
	<li>否则，需要向 <code>s</code> 追加字符，后跟这一组的长度。</li>
</ul>

<p>压缩后得到的字符串 <code>s</code> <strong>不应该直接返回</strong> ，需要转储到字符数组 <code>chars</code> 中。需要注意的是，如果组长度为 <code>10</code> 或 <code>10</code> 以上，则在 <code>chars</code> 数组中会被拆分为多个字符。</p>

<p>请在 <strong>修改完输入数组后</strong> ，返回该数组的新长度。</p>

<p>你必须设计并实现一个只使用常量额外空间的算法来解决此问题。</p>

<p><strong>注意：</strong>数组中超出返回长度的字符无关紧要，应予忽略。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>chars = ["a","a","b","b","c","c","c"]
<strong>输出：</strong>返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
<strong>解释：</strong>"aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>chars = ["a"]
<strong>输出：</strong>返回 1 ，输入数组的前 1 个字符应该是：["a"]
<strong>解释：</strong>唯一的组是“a”，它保持未压缩，因为它是一个字符。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
<strong>输出：</strong>返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
<strong>解释：</strong>由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= chars.length &lt;= 2000</code></li>
	<li><code>chars[i]</code> 可以是小写英文字母、大写英文字母、数字或符号</li>
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
    def compress(self, chars: List[str]) -> int:
        i, k, n = 0, 0, len(chars)
        while i < n:
            j = i + 1
            while j < n and chars[j] == chars[i]:
                j += 1
            chars[k] = chars[i]
            k += 1
            if j - i > 1:
                cnt = str(j - i)
                for c in cnt:
                    chars[k] = c
                    k += 1
            i = j
        return k
```

#### Java

```java
class Solution {
    public int compress(char[] chars) {
        int k = 0, n = chars.length;
        for (int i = 0, j = i + 1; i < n;) {
            while (j < n && chars[j] == chars[i]) {
                ++j;
            }
            chars[k++] = chars[i];
            if (j - i > 1) {
                String cnt = String.valueOf(j - i);
                for (char c : cnt.toCharArray()) {
                    chars[k++] = c;
                }
            }
            i = j;
        }
        return k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0, n = chars.size();
        for (int i = 0, j = i + 1; i < n;) {
            while (j < n && chars[j] == chars[i])
                ++j;
            chars[k++] = chars[i];
            if (j - i > 1) {
                for (char c : to_string(j - i)) {
                    chars[k++] = c;
                }
            }
            i = j;
        }
        return k;
    }
};
```

#### Go

```go
func compress(chars []byte) int {
	i, k, n := 0, 0, len(chars)
	for i < n {
		j := i + 1
		for j < n && chars[j] == chars[i] {
			j++
		}
		chars[k] = chars[i]
		k++
		if j-i > 1 {
			cnt := strconv.Itoa(j - i)
			for _, c := range cnt {
				chars[k] = byte(c)
				k++
			}
		}
		i = j
	}
	return k
}
```

#### Rust

```rust
impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let (mut i, mut k, n) = (0, 0, chars.len());
        while i < n {
            let mut j = i + 1;
            while j < n && chars[j] == chars[i] {
                j += 1;
            }
            chars[k] = chars[i];
            k += 1;

            if j - i > 1 {
                let cnt = (j - i).to_string();
                for c in cnt.chars() {
                    chars[k] = c;
                    k += 1;
                }
            }
            i = j;
        }
        k as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [444. 序列重建 🔒](https://leetcode.cn/problems/sequence-reconstruction){#444}

{{< tabs "444" >}}

{{% tab "python" %}}
```python
class Solution:
    def sequenceReconstruction(
        self, nums: List[int], sequences: List[List[int]]
    ) -> bool:
        n = len(nums)
        g = [[] for _ in range(n)]
        indeg = [0] * n
        for seq in sequences:
            for a, b in pairwise(seq):
                a, b = a - 1, b - 1
                g[a].append(b)
                indeg[b] += 1
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while len(q) == 1:
            i = q.popleft()
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return len(q) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean sequenceReconstruction(int[] nums, List<List<Integer>> sequences) {
        int n = nums.length;
        int[] indeg = new int[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var seq : sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                int a = seq.get(i - 1) - 1, b = seq.get(i) - 1;
                g[a].add(b);
                ++indeg[b];
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (q.size() == 1) {
            int i = q.poll();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return q.isEmpty();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indeg(n);
        vector<int> g[n];
        for (auto& seq : sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                int a = seq[i - 1] - 1, b = seq[i] - 1;
                g[a].push_back(b);
                ++indeg[b];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() == 1) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        return q.empty();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sequenceReconstruction(nums []int, sequences [][]int) bool {
	n := len(nums)
	indeg := make([]int, n)
	g := make([][]int, n)
	for _, seq := range sequences {
		for i, b := range seq[1:] {
			a := seq[i] - 1
			b -= 1
			g[a] = append(g[a], b)
			indeg[b]++
		}
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	for len(q) == 1 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	return len(q) == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sequenceReconstruction(nums: number[], sequences: number[][]): boolean {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg: number[] = Array(n).fill(0);
    for (const seq of sequences) {
        for (let i = 1; i < seq.length; ++i) {
            const [a, b] = [seq[i - 1] - 1, seq[i] - 1];
            g[a].push(b);
            ++indeg[b];
        }
    }
    const q: number[] = indeg.map((v, i) => (v === 0 ? i : -1)).filter(v => v !== -1);
    while (q.length === 1) {
        const i = q.pop()!;
        for (const j of g[i]) {
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return q.length === 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，其中 <code>nums</code> 是范围为 <code>[1，n]</code> 的整数的排列。还提供了一个 2D 整数数组&nbsp;<code>sequences</code>&nbsp;，其中&nbsp;<code>sequences[i]</code>&nbsp;是&nbsp;<code>nums</code>&nbsp;的子序列。<br />
检查 <code>nums</code> 是否是唯一的最短&nbsp;<strong>超序列</strong> 。最短 <strong>超序列</strong> 是 <strong>长度最短</strong> 的序列，并且所有序列&nbsp;<code>sequences[i]</code>&nbsp;都是它的子序列。对于给定的数组&nbsp;<code>sequences</code>&nbsp;，可能存在多个有效的 <strong>超序列</strong> 。</p>

<ul>
	<li>例如，对于&nbsp;<code>sequences = [[1,2],[1,3]]</code>&nbsp;，有两个最短的 <strong>超序列</strong> ，<code>[1,2,3]</code> 和 <code>[1,3,2]</code> 。</li>
	<li>而对于&nbsp;<code>sequences = [[1,2],[1,3],[1,2,3]]</code>&nbsp;，唯一可能的最短 <strong>超序列</strong> 是 <code>[1,2,3]</code> 。<code>[1,2,3,4]</code> 是可能的超序列，但不是最短的。</li>
</ul>

<p><em>如果 <code>nums</code> 是序列的唯一最短 <strong>超序列</strong> ，则返回 <code>true</code> ，否则返回 <code>false</code> 。</em><br />
<strong>子序列</strong> 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，而不改变其余元素的顺序的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], sequences = [[1,2],[1,3]]
<strong>输出：</strong>false
<strong>解释：</strong>有两种可能的超序列：[1,2,3]和[1,3,2]。
序列 [1,2] 是[<u><strong>1,2</strong></u>,3]和[<u><strong>1</strong></u>,3,<u><strong>2</strong></u>]的子序列。
序列 [1,3] 是[<u><strong>1</strong></u>,2,<u><strong>3</strong></u>]和[<u><strong>1,3</strong></u>,2]的子序列。
因为 nums 不是唯一最短的超序列，所以返回false。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], sequences = [[1,2]]
<strong>输出：</strong>false
<strong>解释：</strong>最短可能的超序列为 [1,2]。
序列 [1,2] 是它的子序列：[<u><strong>1,2</strong></u>]。
因为 nums 不是最短的超序列，所以返回false。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
<strong>输出：</strong>true
<strong>解释：</strong>最短可能的超序列为[1,2,3]。
序列 [1,2] 是它的一个子序列：[<strong>1,2</strong>,3]。
序列 [1,3] 是它的一个子序列：[<u><strong>1</strong></u>,2,<u><strong>3</strong></u>]。
序列 [2,3] 是它的一个子序列：[1,<u><strong>2,3</strong></u>]。
因为 nums 是唯一最短的超序列，所以返回true。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code>&nbsp;是&nbsp;<code>[1, n]</code>&nbsp;范围内所有整数的排列</li>
	<li><code>1 &lt;= sequences.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sequences[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sum(sequences[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sequences[i][j] &lt;= n</code></li>
	<li><code>sequences</code>&nbsp;的所有数组都是 <strong>唯一 </strong>的</li>
	<li><code>sequences[i]</code>&nbsp;是&nbsp;<code>nums</code> 的一个子序列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们可以先遍历每个子序列 `seq`，对于每个相邻的元素 $a$ 和 $b$，我们在 $a$ 和 $b$ 之间建立一条有向边 $a \to b$。同时统计每个节点的入度，最后将所有入度为 $0$ 的节点加入队列中。

当队列中的节点个数等于 $1$ 时，我们取出队首节点 $i$，将 $i$ 从图中删除，并将 $i$ 的所有相邻节点的入度减 $1$。如果减 $1$ 后相邻节点的入度为 $0$，则将这些节点加入队列中。重复上述操作，直到队列的长度不为 $1$。此时判断队列是否为空，如果不为空，说明有多个最短超序列，返回 `false`；如果为空，说明只有一个最短超序列，返回 `true`。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点的个数和边的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sequenceReconstruction(
        self, nums: List[int], sequences: List[List[int]]
    ) -> bool:
        n = len(nums)
        g = [[] for _ in range(n)]
        indeg = [0] * n
        for seq in sequences:
            for a, b in pairwise(seq):
                a, b = a - 1, b - 1
                g[a].append(b)
                indeg[b] += 1
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while len(q) == 1:
            i = q.popleft()
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return len(q) == 0
```

#### Java

```java
class Solution {
    public boolean sequenceReconstruction(int[] nums, List<List<Integer>> sequences) {
        int n = nums.length;
        int[] indeg = new int[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var seq : sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                int a = seq.get(i - 1) - 1, b = seq.get(i) - 1;
                g[a].add(b);
                ++indeg[b];
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (q.size() == 1) {
            int i = q.poll();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return q.isEmpty();
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indeg(n);
        vector<int> g[n];
        for (auto& seq : sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                int a = seq[i - 1] - 1, b = seq[i] - 1;
                g[a].push_back(b);
                ++indeg[b];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() == 1) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        return q.empty();
    }
};
```

#### Go

```go
func sequenceReconstruction(nums []int, sequences [][]int) bool {
	n := len(nums)
	indeg := make([]int, n)
	g := make([][]int, n)
	for _, seq := range sequences {
		for i, b := range seq[1:] {
			a := seq[i] - 1
			b -= 1
			g[a] = append(g[a], b)
			indeg[b]++
		}
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	for len(q) == 1 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	return len(q) == 0
}
```

#### TypeScript

```ts
function sequenceReconstruction(nums: number[], sequences: number[][]): boolean {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg: number[] = Array(n).fill(0);
    for (const seq of sequences) {
        for (let i = 1; i < seq.length; ++i) {
            const [a, b] = [seq[i - 1] - 1, seq[i] - 1];
            g[a].push(b);
            ++indeg[b];
        }
    }
    const q: number[] = indeg.map((v, i) => (v === 0 ? i : -1)).filter(v => v !== -1);
    while (q.length === 1) {
        const i = q.pop()!;
        for (const j of g[i]) {
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return q.length === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [445. 两数相加 II](https://leetcode.cn/problems/add-two-numbers-ii){#445}

{{< tabs "445" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        s1, s2 = [], []
        while l1:
            s1.append(l1.val)
            l1 = l1.next
        while l2:
            s2.append(l2.val)
            l2 = l2.next
        dummy = ListNode()
        carry = 0
        while s1 or s2 or carry:
            s = (0 if not s1 else s1.pop()) + (0 if not s2 else s2.pop()) + carry
            carry, val = divmod(s, 10)
            # node = ListNode(val, dummy.next)
            # dummy.next = node
            dummy.next = ListNode(val, dummy.next)
        return dummy.next
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Deque<Integer> s1 = new ArrayDeque<>();
        Deque<Integer> s2 = new ArrayDeque<>();
        for (; l1 != null; l1 = l1.next) {
            s1.push(l1.val);
        }
        for (; l2 != null; l2 = l2.next) {
            s2.push(l2.val);
        }
        ListNode dummy = new ListNode();
        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int s = (s1.isEmpty() ? 0 : s1.pop()) + (s2.isEmpty() ? 0 : s2.pop()) + carry;
            // ListNode node = new ListNode(s % 10, dummy.next);
            // dummy.next = node;
            dummy.next = new ListNode(s % 10, dummy.next);
            carry = s / 10;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        for (; l1; l1 = l1->next) s1.push(l1->val);
        for (; l2; l2 = l2->next) s2.push(l2->val);
        ListNode* dummy = new ListNode();
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int s = carry;
            if (!s1.empty()) {
                s += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                s += s2.top();
                s2.pop();
            }
            // ListNode* node = new ListNode(s % 10, dummy->next);
            // dummy->next = node;
            dummy->next = new ListNode(s % 10, dummy->next);
            carry = s / 10;
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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	s1, s2 := arraystack.New(), arraystack.New()
	for l1 != nil {
		s1.Push(l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		s2.Push(l2.Val)
		l2 = l2.Next
	}
	carry, dummy := 0, new(ListNode)
	for !s1.Empty() || !s2.Empty() || carry > 0 {
		s := carry
		v, ok := s1.Pop()
		if ok {
			s += v.(int)
		}
		v, ok = s2.Pop()
		if ok {
			s += v.(int)
		}
		// node := &ListNode{s % 10, dummy.Next}
		// dummy.Next = node
		dummy.Next = &ListNode{s % 10, dummy.Next}
		carry = s / 10
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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const s1: number[] = [];
    const s2: number[] = [];
    for (; l1; l1 = l1.next) {
        s1.push(l1.val);
    }
    for (; l2; l2 = l2.next) {
        s2.push(l2.val);
    }
    const dummy = new ListNode();
    let carry = 0;
    while (s1.length || s2.length || carry) {
        const s = (s1.pop() ?? 0) + (s2.pop() ?? 0) + carry;
        // const node = new ListNode(s % 10, dummy.next);
        // dummy.next = node;
        dummy.next = new ListNode(s % 10, dummy.next);
        carry = Math.floor(s / 10);
    }
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    fn create_stack(mut head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut res = vec![];
        while let Some(node) = head {
            res.push(node.val);
            head = node.next;
        }
        res
    }

    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut s1 = Self::create_stack(l1);
        let mut s2 = Self::create_stack(l2);

        let mut dummy = Box::new(ListNode::new(0));
        let mut carry = 0;
        while !s1.is_empty() || !s2.is_empty() || carry != 0 {
            if let Some(val) = s1.pop() {
                carry += val;
            }
            if let Some(val) = s2.pop() {
                carry += val;
            }
            dummy.next = Some(Box::new(ListNode {
                val: carry % 10,
                next: dummy.next.take(),
            }));
            carry /= 10;
        }
        dummy.next.take()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>非空 </strong>链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数字都不会以零开头。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0445.Add%20Two%20Numbers%20II/images/1626420025-fZfzMX-image.png" style="width: 302px; " /></p>

<pre>
<strong>输入：</strong>l1 = [7,2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[7,8,0,7]
</pre>

<p><strong>示例2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[8,0,7]
</pre>

<p><strong>示例3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [0], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为<code> [1, 100]</code></li>
	<li><code>0 &lt;= node.val &lt;= 9</code></li>
	<li>输入数据保证链表代表的数字无前导 0</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果输入链表不能翻转该如何解决？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：翻转

手动翻转链表 `l1` 与 `l2`，将此题转换为 [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)，相加过程一致。对于最后返回的结果链表也需要进行翻转，共计三次。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        s1, s2 = [], []
        while l1:
            s1.append(l1.val)
            l1 = l1.next
        while l2:
            s2.append(l2.val)
            l2 = l2.next
        dummy = ListNode()
        carry = 0
        while s1 or s2 or carry:
            s = (0 if not s1 else s1.pop()) + (0 if not s2 else s2.pop()) + carry
            carry, val = divmod(s, 10)
            # node = ListNode(val, dummy.next)
            # dummy.next = node
            dummy.next = ListNode(val, dummy.next)
        return dummy.next
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Deque<Integer> s1 = new ArrayDeque<>();
        Deque<Integer> s2 = new ArrayDeque<>();
        for (; l1 != null; l1 = l1.next) {
            s1.push(l1.val);
        }
        for (; l2 != null; l2 = l2.next) {
            s2.push(l2.val);
        }
        ListNode dummy = new ListNode();
        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int s = (s1.isEmpty() ? 0 : s1.pop()) + (s2.isEmpty() ? 0 : s2.pop()) + carry;
            // ListNode node = new ListNode(s % 10, dummy.next);
            // dummy.next = node;
            dummy.next = new ListNode(s % 10, dummy.next);
            carry = s / 10;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        for (; l1; l1 = l1->next) s1.push(l1->val);
        for (; l2; l2 = l2->next) s2.push(l2->val);
        ListNode* dummy = new ListNode();
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int s = carry;
            if (!s1.empty()) {
                s += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                s += s2.top();
                s2.pop();
            }
            // ListNode* node = new ListNode(s % 10, dummy->next);
            // dummy->next = node;
            dummy->next = new ListNode(s % 10, dummy->next);
            carry = s / 10;
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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	s1, s2 := arraystack.New(), arraystack.New()
	for l1 != nil {
		s1.Push(l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		s2.Push(l2.Val)
		l2 = l2.Next
	}
	carry, dummy := 0, new(ListNode)
	for !s1.Empty() || !s2.Empty() || carry > 0 {
		s := carry
		v, ok := s1.Pop()
		if ok {
			s += v.(int)
		}
		v, ok = s2.Pop()
		if ok {
			s += v.(int)
		}
		// node := &ListNode{s % 10, dummy.Next}
		// dummy.Next = node
		dummy.Next = &ListNode{s % 10, dummy.Next}
		carry = s / 10
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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const s1: number[] = [];
    const s2: number[] = [];
    for (; l1; l1 = l1.next) {
        s1.push(l1.val);
    }
    for (; l2; l2 = l2.next) {
        s2.push(l2.val);
    }
    const dummy = new ListNode();
    let carry = 0;
    while (s1.length || s2.length || carry) {
        const s = (s1.pop() ?? 0) + (s2.pop() ?? 0) + carry;
        // const node = new ListNode(s % 10, dummy.next);
        // dummy.next = node;
        dummy.next = new ListNode(s % 10, dummy.next);
        carry = Math.floor(s / 10);
    }
    return dummy.next;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    fn reverse(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut pre = None;
        while let Some(mut node) = head {
            let next = node.next.take();
            node.next = pre.take();
            pre = Some(node);
            head = next;
        }
        pre
    }

    pub fn add_two_numbers(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        l1 = Self::reverse(l1);
        l2 = Self::reverse(l2);
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut cur = &mut dummy;
        let mut sum = 0;
        while l1.is_some() || l2.is_some() || sum != 0 {
            if let Some(node) = l1 {
                sum += node.val;
                l1 = node.next;
            }
            if let Some(node) = l2 {
                sum += node.val;
                l2 = node.next;
            }
            cur.as_mut().unwrap().next = Some(Box::new(ListNode::new(sum % 10)));
            cur = &mut cur.as_mut().unwrap().next;
            sum /= 10;
        }
        Self::reverse(dummy.unwrap().next.take())
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈

我们可以使用两个栈 $s1$ 和 $s2$ 分别存储两个链表元素，然后同时遍历两个栈，并使用变量 $carry$ 表示当前是否有进位。

遍历时，我们弹出对应栈的栈顶元素，计算它们与进位 $carry$ 的和，然后更新进位的值，并创建一个链表节点，插入答案链表的头部。如果两个栈都遍历结束，并且进位为 $0$ 时，遍历结束。

最后我们返回答案链表的头节点即可。

时间复杂度 $O(\max(m, n))$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为两个链表的长度。

<!-- tabs:start -->

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    fn create_stack(mut head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut res = vec![];
        while let Some(node) = head {
            res.push(node.val);
            head = node.next;
        }
        res
    }

    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut s1 = Self::create_stack(l1);
        let mut s2 = Self::create_stack(l2);

        let mut dummy = Box::new(ListNode::new(0));
        let mut carry = 0;
        while !s1.is_empty() || !s2.is_empty() || carry != 0 {
            if let Some(val) = s1.pop() {
                carry += val;
            }
            if let Some(val) = s2.pop() {
                carry += val;
            }
            dummy.next = Some(Box::new(ListNode {
                val: carry % 10,
                next: dummy.next.take(),
            }));
            carry /= 10;
        }
        dummy.next.take()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence){#446}

{{< tabs "446" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        f = [defaultdict(int) for _ in nums]
        ans = 0
        for i, x in enumerate(nums):
            for j, y in enumerate(nums[:i]):
                d = x - y
                ans += f[j][d]
                f[i][d] += f[j][d] + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        Map<Long, Integer>[] f = new Map[n];
        Arrays.setAll(f, k -> new HashMap<>());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                Long d = 1L * nums[i] - nums[j];
                int cnt = f[j].getOrDefault(d, 0);
                ans += cnt;
                f[i].merge(d, cnt + 1, Integer::sum);
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> f[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = 1LL * nums[i] - nums[j];
                int cnt = f[j][d];
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfArithmeticSlices(nums []int) (ans int) {
	f := make([]map[int]int, len(nums))
	for i := range f {
		f[i] = map[int]int{}
	}
	for i, x := range nums {
		for j, y := range nums[:i] {
			d := x - y
			cnt := f[j][d]
			ans += cnt
			f[i][d] += cnt + 1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfArithmeticSlices(nums: number[]): number {
    const n = nums.length;
    const f: Map<number, number>[] = new Array(n).fill(0).map(() => new Map());
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const d = nums[i] - nums[j];
            const cnt = f[j].get(d) || 0;
            ans += cnt;
            f[i].set(d, (f[i].get(d) || 0) + cnt + 1);
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

<p>给你一个整数数组 <code>nums</code> ，返回 <code>nums</code> 中所有 <strong>等差子序列</strong> 的数目。</p>

<p>如果一个序列中 <strong>至少有三个元素</strong> ，并且任意两个相邻元素之差相同，则称该序列为等差序列。</p>

<ul>
	<li>例如，<code>[1, 3, 5, 7, 9]</code>、<code>[7, 7, 7, 7]</code> 和 <code>[3, -1, -5, -9]</code> 都是等差序列。</li>
	<li>再例如，<code>[1, 1, 2, 5, 7]</code> 不是等差序列。</li>
</ul>

<p>数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列。</p>

<ul>
	<li>例如，<code>[2,5,10]</code> 是 <code>[1,2,1,<em><strong>2</strong></em>,4,1,<strong><em>5</em></strong>,<em><strong>10</strong></em>]</code> 的一个子序列。</li>
</ul>

<p>题目数据保证答案是一个 <strong>32-bit</strong> 整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,6,8,10]
<strong>输出：</strong>7
<strong>解释：</strong>所有的等差子序列为：
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,7,7,7,7]
<strong>输出：</strong>16
<strong>解释：</strong>数组中的任意子序列都是等差子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1&nbsp; &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 哈希表

我们定义 $f[i][d]$ 表示以 $nums[i]$ 为结尾，公差为 $d$ 的弱等差子序列（最少有两个元素）的个数。由于 $d$ 的范围很大，所以我们使用哈希表来统计。

接下来，我们枚举 $nums$ 中的所有元素对 $(nums[i], nums[j])$，其中 $j \lt i$。我们将其作为等差数列的最后两个元素，由此即可得到公差 $d = nums[i] - nums[j]$。由于公差相同，我们可以将 $nums[i]$ 加到以 $nums[j]$ 为结尾的弱等差子序列的末尾，此时以 $nums[i]$ 为结尾的等差子序列的数量为 $f[j][d]$，我们将其加入答案。然后，我们再将 $nums[i]$ 加到以 $nums[j]$ 为结尾的弱等差子序列的末尾，这对应着状态转移 $f[i][d] += f[j][d]$。同时，$(nums[i], nums[j])$ 这一对元素也可以当作一个弱等差子序列，因此有状态转移 $f[i][d] += f[j][d] + 1$。

枚举结束，返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        f = [defaultdict(int) for _ in nums]
        ans = 0
        for i, x in enumerate(nums):
            for j, y in enumerate(nums[:i]):
                d = x - y
                ans += f[j][d]
                f[i][d] += f[j][d] + 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        Map<Long, Integer>[] f = new Map[n];
        Arrays.setAll(f, k -> new HashMap<>());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                Long d = 1L * nums[i] - nums[j];
                int cnt = f[j].getOrDefault(d, 0);
                ans += cnt;
                f[i].merge(d, cnt + 1, Integer::sum);
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> f[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = 1LL * nums[i] - nums[j];
                int cnt = f[j][d];
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfArithmeticSlices(nums []int) (ans int) {
	f := make([]map[int]int, len(nums))
	for i := range f {
		f[i] = map[int]int{}
	}
	for i, x := range nums {
		for j, y := range nums[:i] {
			d := x - y
			cnt := f[j][d]
			ans += cnt
			f[i][d] += cnt + 1
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfArithmeticSlices(nums: number[]): number {
    const n = nums.length;
    const f: Map<number, number>[] = new Array(n).fill(0).map(() => new Map());
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const d = nums[i] - nums[j];
            const cnt = f[j].get(d) || 0;
            ans += cnt;
            f[i].set(d, (f[i].get(d) || 0) + cnt + 1);
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

# [447. 回旋镖的数量](https://leetcode.cn/problems/number-of-boomerangs){#447}

{{< tabs "447" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p1 in points:
            cnt = Counter()
            for p2 in points:
                d = dist(p1, p2)
                cnt[d] += 1
            ans += sum(x * (x - 1) for x in cnt.values())
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] p1 : points) {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int[] p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                cnt.merge(d, 1, Integer::sum);
            }
            for (int x : cnt.values()) {
                ans += x * (x - 1);
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& p1 : points) {
            unordered_map<int, int> cnt;
            for (auto& p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                cnt[d]++;
            }
            for (auto& [_, x] : cnt) {
                ans += x * (x - 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfBoomerangs(points [][]int) (ans int) {
	for _, p1 := range points {
		cnt := map[int]int{}
		for _, p2 := range points {
			d := (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])
			cnt[d]++
		}
		for _, x := range cnt {
			ans += x * (x - 1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfBoomerangs(points: number[][]): number {
    let ans = 0;
    for (const [x1, y1] of points) {
        const cnt: Map<number, number> = new Map();
        for (const [x2, y2] of points) {
            const d = (x1 - x2) ** 2 + (y1 - y2) ** 2;
            cnt.set(d, (cnt.get(d) || 0) + 1);
        }
        for (const [_, x] of cnt) {
            ans += x * (x - 1);
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

<p>给定平面上<em>&nbsp;</em><code>n</code><em> </em>对 <strong>互不相同</strong> 的点&nbsp;<code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。<strong>回旋镖</strong> 是由点&nbsp;<code>(i, j, k)</code> 表示的元组 ，其中&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;之间的欧式距离和&nbsp;<code>i</code>&nbsp;和&nbsp;<code>k</code>&nbsp;之间的欧式距离相等（<strong>需要考虑元组的顺序</strong>）。</p>

<p>返回平面上所有回旋镖的数量。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[0,0],[1,0],[2,0]]
<strong>输出：</strong>2
<strong>解释：</strong>两个回旋镖为 <strong>[[1,0],[0,0],[2,0]]</strong> 和 <strong>[[1,0],[2,0],[0,0]]</strong>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n ==&nbsp;points.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>所有点都 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 计数

我们可以枚举 `points` 中的每个点作为回旋镖的点 $i$，然后用一个哈希表 $cnt$ 记录其他点到 $i$ 的距离出现的次数。

如果有 $x$ 个点到 $i$ 的距离相等，那么我们可以任选其中 $2$ 个点作为回旋镖的 $j$ 和 $k$，方案数为 $A_x^2 = x \times (x - 1)$。因此，我们对哈希表中的每个值 $x$，都计算并累加 $A_x^2$，就可以得到满足题目要求的回旋镖数量之和。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `points` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p1 in points:
            cnt = Counter()
            for p2 in points:
                d = dist(p1, p2)
                ans += cnt[d]
                cnt[d] += 1
        return ans << 1
```

#### Java

```java
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] p1 : points) {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int[] p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                ans += cnt.getOrDefault(d, 0);
                cnt.merge(d, 1, Integer::sum);
            }
        }
        return ans << 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& p1 : points) {
            unordered_map<int, int> cnt;
            for (auto& p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                ans += cnt[d];
                cnt[d]++;
            }
        }
        return ans << 1;
    }
};
```

#### Go

```go
func numberOfBoomerangs(points [][]int) (ans int) {
	for _, p1 := range points {
		cnt := map[int]int{}
		for _, p2 := range points {
			d := (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])
			ans += cnt[d]
			cnt[d]++
		}
	}
	ans <<= 1
	return
}
```

#### TypeScript

```ts
function numberOfBoomerangs(points: number[][]): number {
    let ans = 0;
    for (const [x1, y1] of points) {
        const cnt: Map<number, number> = new Map();
        for (const [x2, y2] of points) {
            const d = (x1 - x2) ** 2 + (y1 - y2) ** 2;
            ans += cnt.get(d) || 0;
            cnt.set(d, (cnt.get(d) || 0) + 1);
        }
    }
    return ans << 1;
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
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p1 in points:
            cnt = Counter()
            for p2 in points:
                d = dist(p1, p2)
                cnt[d] += 1
            ans += sum(x * (x - 1) for x in cnt.values())
        return ans
```

#### Java

```java
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] p1 : points) {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int[] p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                cnt.merge(d, 1, Integer::sum);
            }
            for (int x : cnt.values()) {
                ans += x * (x - 1);
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& p1 : points) {
            unordered_map<int, int> cnt;
            for (auto& p2 : points) {
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                cnt[d]++;
            }
            for (auto& [_, x] : cnt) {
                ans += x * (x - 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfBoomerangs(points [][]int) (ans int) {
	for _, p1 := range points {
		cnt := map[int]int{}
		for _, p2 := range points {
			d := (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])
			cnt[d]++
		}
		for _, x := range cnt {
			ans += x * (x - 1)
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfBoomerangs(points: number[][]): number {
    let ans = 0;
    for (const [x1, y1] of points) {
        const cnt: Map<number, number> = new Map();
        for (const [x2, y2] of points) {
            const d = (x1 - x2) ** 2 + (y1 - y2) ** 2;
            cnt.set(d, (cnt.get(d) || 0) + 1);
        }
        for (const [_, x] of cnt) {
            ans += x * (x - 1);
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

# [448. 找到所有数组中消失的数字](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array){#448}

{{< tabs "448" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for x in nums:
            i = abs(x) - 1
            if nums[i] > 0:
                nums[i] *= -1
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        for (int x : nums) {
            int i = Math.abs(x) - 1;
            if (nums[i] > 0) {
                nums[i] *= -1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.add(i + 1);
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int& x : nums) {
            int i = abs(x) - 1;
            if (nums[i] > 0) {
                nums[i] = -nums[i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDisappearedNumbers(nums []int) (ans []int) {
	n := len(nums)
	for _, x := range nums {
		i := abs(x) - 1
		if nums[i] > 0 {
			nums[i] = -nums[i]
		}
	}
	for i := 0; i < n; i++ {
		if nums[i] > 0 {
			ans = append(ans, i+1)
		}
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
function findDisappearedNumbers(nums: number[]): number[] {
    const n = nums.length;
    for (const x of nums) {
        const i = Math.abs(x) - 1;
        if (nums[i] > 0) {
            nums[i] *= -1;
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            ans.push(i + 1);
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

<p>给你一个含 <code>n</code> 个整数的数组 <code>nums</code> ，其中 <code>nums[i]</code> 在区间 <code>[1, n]</code> 内。请你找出所有在 <code>[1, n]</code> 范围内但没有出现在 <code>nums</code> 中的数字，并以数组的形式返回结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,2,7,8,2,3,1]
<strong>输出：</strong>[5,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= n</code></li>
</ul>

<p><strong>进阶：</strong>你能在不使用额外空间且时间复杂度为<em> </em><code>O(n)</code><em> </em>的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们可以使用数组或哈希表记录数组中的数字，然后遍历 `[1, n]` 区间内的数字，若数字不存在于数组或哈希表中，则说明数组中缺失该数字，将其添加到结果列表中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        s = set(nums)
        return [x for x in range(1, len(nums) + 1) if x not in s]
```

#### Java

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        boolean[] s = new boolean[n + 1];
        for (int x : nums) {
            s[x] = true;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (!s[i]) {
                ans.add(i);
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        bool s[n + 1];
        memset(s, false, sizeof(s));
        for (int& x : nums) {
            s[x] = true;
        }
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (!s[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findDisappearedNumbers(nums []int) (ans []int) {
	n := len(nums)
	s := make([]bool, n+1)
	for _, x := range nums {
		s[x] = true
	}
	for i := 1; i <= n; i++ {
		if !s[i] {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findDisappearedNumbers(nums: number[]): number[] {
    const n = nums.length;
    const s: boolean[] = new Array(n + 1).fill(false);
    for (const x of nums) {
        s[x] = true;
    }
    const ans: number[] = [];
    for (let i = 1; i <= n; ++i) {
        if (!s[i]) {
            ans.push(i);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：原地修改

我们可以遍历数组 $nums$，将 $|nums[i]|-1$ 位置的数字标记为负数，表示数组 $nums[i]$ 出现过。最后遍历数组 $nums$，若 $nums[i]$ 为正数，则说明数组中缺失 $i+1$，将其添加到结果列表中。

遍历结束后，返回结果列表即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for x in nums:
            i = abs(x) - 1
            if nums[i] > 0:
                nums[i] *= -1
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
```

#### Java

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        for (int x : nums) {
            int i = Math.abs(x) - 1;
            if (nums[i] > 0) {
                nums[i] *= -1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.add(i + 1);
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int& x : nums) {
            int i = abs(x) - 1;
            if (nums[i] > 0) {
                nums[i] = -nums[i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findDisappearedNumbers(nums []int) (ans []int) {
	n := len(nums)
	for _, x := range nums {
		i := abs(x) - 1
		if nums[i] > 0 {
			nums[i] = -nums[i]
		}
	}
	for i := 0; i < n; i++ {
		if nums[i] > 0 {
			ans = append(ans, i+1)
		}
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
function findDisappearedNumbers(nums: number[]): number[] {
    const n = nums.length;
    for (const x of nums) {
        const i = Math.abs(x) - 1;
        if (nums[i] > 0) {
            nums[i] *= -1;
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            ans.push(i + 1);
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

# [449. 序列化和反序列化二叉搜索树](https://leetcode.cn/problems/serialize-and-deserialize-bst){#449}

{{< tabs "449" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string."""

        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            nums.append(root.val)
            dfs(root.left)
            dfs(root.right)

        nums = []
        dfs(root)
        return " ".join(map(str, nums))

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree."""

        def dfs(mi: int, mx: int) -> Optional[TreeNode]:
            nonlocal i
            if i == len(nums) or not mi <= nums[i] <= mx:
                return None
            x = nums[i]
            root = TreeNode(x)
            i += 1
            root.left = dfs(mi, x)
            root.right = dfs(x, mx)
            return root

        nums = list(map(int, data.split()))
        i = 0
        return dfs(-inf, inf)


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
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
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private int i;
    private List<String> nums;
    private final int inf = 1 << 30;

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        nums = new ArrayList<>();
        dfs(root);
        return String.join(" ", nums);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || "".equals(data)) {
            return null;
        }
        i = 0;
        nums = Arrays.asList(data.split(" "));
        return dfs(-inf, inf);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        nums.add(String.valueOf(root.val));
        dfs(root.left);
        dfs(root.right);
    }

    private TreeNode dfs(int mi, int mx) {
        if (i == nums.size()) {
            return null;
        }
        int x = Integer.parseInt(nums.get(i));
        if (x < mi || x > mx) {
            return null;
        }
        TreeNode root = new TreeNode(x);
        ++i;
        root.left = dfs(mi, x);
        root.right = dfs(x, mx);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string data = "";
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            data += to_string(root->val) + " ";
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<int> nums = split(data, ' ');
        int i = 0;
        function<TreeNode*(int, int)> dfs = [&](int mi, int mx) -> TreeNode* {
            if (i == nums.size() || nums[i] < mi || nums[i] > mx) {
                return nullptr;
            }
            int x = nums[i++];
            TreeNode* root = new TreeNode(x);
            root->left = dfs(mi, x);
            root->right = dfs(x, mx);
            return root;
        };
        return dfs(INT_MIN, INT_MAX);
    }

    vector<int> split(const string& s, char delim) {
        vector<int> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.push_back(stoi(token));
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
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

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	data := &strings.Builder{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		data.WriteString(strconv.Itoa(root.Val))
		data.WriteByte(' ')
		dfs(root.Left)
		dfs(root.Right)
	}
	dfs(root)
	return data.String()[0 : data.Len()-1]
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == "" {
		return nil
	}
	vals := strings.Split(data, " ")
	i := 0
	var dfs func(int, int) *TreeNode
	dfs = func(mi, mx int) *TreeNode {
		if i == len(vals) {
			return nil
		}
		x, _ := strconv.Atoi(vals[i])
		if x < mi || x > mx {
			return nil
		}
		i++
		root := &TreeNode{Val: x}
		root.Left = dfs(mi, x)
		root.Right = dfs(x, mx)
		return root
	}
	return dfs(math.MinInt64, math.MaxInt64)
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor()
 * deser := Constructor()
 * tree := ser.serialize(root)
 * ans := deser.deserialize(tree)
 * return ans
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。</p>

<p>设计一个算法来序列化和反序列化<strong> 二叉搜索树</strong> 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。</p>

<p><strong>编码的字符串应尽可能紧凑。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>[2,1,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数范围是 <code>[0, 10<sup>4</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>题目数据 <strong>保证</strong> 输入的树是一棵二叉搜索树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：先序遍历

题目给定的是二叉搜索树，我们知道二叉搜索树的中序遍历是有序的，而通过“先序遍历”和“中序遍历”可以唯一确定一棵二叉树，所以我们可以通过先序遍历的结果和中序遍历的结果来唯一确定一棵二叉搜索树。

在 `serialize` 方法中，我们使用先序遍历的方式将二叉搜索树序列化为空格分隔的字符串，然后在 `deserialize` 方法中，我们将字符串按空格分割为数组，然后使用递归的方式来构建二叉搜索树。递归函数为 $dfs(mi, mx)$，表示当前节点的值必须在 $[mi, mx]$ 之间，如果当前节点的值不在 $[mi, mx]$ 之间，则说明这个节点不是当前递归树的节点，返回 `None`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string."""

        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            nums.append(root.val)
            dfs(root.left)
            dfs(root.right)

        nums = []
        dfs(root)
        return " ".join(map(str, nums))

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree."""

        def dfs(mi: int, mx: int) -> Optional[TreeNode]:
            nonlocal i
            if i == len(nums) or not mi <= nums[i] <= mx:
                return None
            x = nums[i]
            root = TreeNode(x)
            i += 1
            root.left = dfs(mi, x)
            root.right = dfs(x, mx)
            return root

        nums = list(map(int, data.split()))
        i = 0
        return dfs(-inf, inf)


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private int i;
    private List<String> nums;
    private final int inf = 1 << 30;

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        nums = new ArrayList<>();
        dfs(root);
        return String.join(" ", nums);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || "".equals(data)) {
            return null;
        }
        i = 0;
        nums = Arrays.asList(data.split(" "));
        return dfs(-inf, inf);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        nums.add(String.valueOf(root.val));
        dfs(root.left);
        dfs(root.right);
    }

    private TreeNode dfs(int mi, int mx) {
        if (i == nums.size()) {
            return null;
        }
        int x = Integer.parseInt(nums.get(i));
        if (x < mi || x > mx) {
            return null;
        }
        TreeNode root = new TreeNode(x);
        ++i;
        root.left = dfs(mi, x);
        root.right = dfs(x, mx);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string data = "";
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            data += to_string(root->val) + " ";
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<int> nums = split(data, ' ');
        int i = 0;
        function<TreeNode*(int, int)> dfs = [&](int mi, int mx) -> TreeNode* {
            if (i == nums.size() || nums[i] < mi || nums[i] > mx) {
                return nullptr;
            }
            int x = nums[i++];
            TreeNode* root = new TreeNode(x);
            root->left = dfs(mi, x);
            root->right = dfs(x, mx);
            return root;
        };
        return dfs(INT_MIN, INT_MAX);
    }

    vector<int> split(const string& s, char delim) {
        vector<int> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.push_back(stoi(token));
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
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

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	data := &strings.Builder{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		data.WriteString(strconv.Itoa(root.Val))
		data.WriteByte(' ')
		dfs(root.Left)
		dfs(root.Right)
	}
	dfs(root)
	return data.String()[0 : data.Len()-1]
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == "" {
		return nil
	}
	vals := strings.Split(data, " ")
	i := 0
	var dfs func(int, int) *TreeNode
	dfs = func(mi, mx int) *TreeNode {
		if i == len(vals) {
			return nil
		}
		x, _ := strconv.Atoi(vals[i])
		if x < mi || x > mx {
			return nil
		}
		i++
		root := &TreeNode{Val: x}
		root.Left = dfs(mi, x)
		root.Right = dfs(x, mx)
		return root
	}
	return dfs(math.MinInt64, math.MaxInt64)
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor()
 * deser := Constructor()
 * tree := ser.serialize(root)
 * ans := deser.deserialize(tree)
 * return ans
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
