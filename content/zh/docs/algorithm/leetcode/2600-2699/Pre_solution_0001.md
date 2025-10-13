---
title: "2600_K 件物品的最大和"
date: 2025-10-08T18:39:28+08:00
weight: 1
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 图, 字符串, 广度优先搜索, 拓扑排序, 排序, 数学, 数组, 数论, 枚举, 树, 贪心]
---

{{< markmap >}}
### [2600_K 件物品的最大和](#2600)
#### [贪心](#2600)
#### [数学](#2600)
### [2601_质数减法运算](#2601)
#### [贪心](#2601)
#### [数组](#2601)
#### [数学](#2601)
#### [二分查找](#2601)
#### [数论](#2601)
### [2602_使数组元素全部相等的最少操作次数](#2602)
#### [数组](#2602)
#### [二分查找](#2602)
#### [前缀和](#2602)
#### [排序](#2602)
### [2603_收集树中金币](#2603)
#### [树](#2603)
#### [图](#2603)
#### [拓扑排序](#2603)
#### [数组](#2603)
### [2604_吃掉所有谷子的最短时间 🔒](#2604)
#### [数组](#2604)
#### [双指针](#2604)
#### [二分查找](#2604)
#### [排序](#2604)
### [2605_从两个数字数组里生成最小数字](#2605)
#### [数组](#2605)
#### [哈希表](#2605)
#### [枚举](#2605)
### [2606_找到最大开销的子字符串](#2606)
#### [数组](#2606)
#### [哈希表](#2606)
#### [字符串](#2606)
#### [动态规划](#2606)
### [2607_使子数组元素和相等](#2607)
#### [贪心](#2607)
#### [数组](#2607)
#### [数学](#2607)
#### [数论](#2607)
#### [排序](#2607)
### [2608_图中的最短环](#2608)
#### [广度优先搜索](#2608)
#### [图](#2608)
### [2609_最长平衡子字符串](#2609)
#### [字符串](#2609)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2600_K 件物品的最大和
___
#### 贪心
___
#### 数学
---
### 2601_质数减法运算
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 数论
---
### 2602_使数组元素全部相等的最少操作次数
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
---
### 2603_收集树中金币
___
#### 树
___
#### 图
___
#### 拓扑排序
___
#### 数组
---
### 2604_吃掉所有谷子的最短时间 🔒
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2605_从两个数字数组里生成最小数字
___
#### 数组
___
#### 哈希表
___
#### 枚举
---
### 2606_找到最大开销的子字符串
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 2607_使子数组元素和相等
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
---
### 2608_图中的最短环
___
#### 广度优先搜索
___
#### 图
---
### 2609_最长平衡子字符串
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 字符串 | 广度优先搜索 | 拓扑排序 |
| 排序 | 数学 | 数组 |
| 数论 | 枚举 | 树 |
| 贪心 |  |  |

# [2600. K 件物品的最大和](https://leetcode.cn/problems/k-items-with-the-maximum-sum){#2600}

{{< tabs "2600" >}}

{{% tab "python" %}}
```python
class Solution:
    def kItemsWithMaximumSum(
        self, numOnes: int, numZeros: int, numNegOnes: int, k: int
    ) -> int:
        if numOnes >= k:
            return k
        if numZeros >= k - numOnes:
            return numOnes
        return numOnes - (k - numOnes - numZeros)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kItemsWithMaximumSum(numOnes int, numZeros int, numNegOnes int, k int) int {
	if numOnes >= k {
		return k
	}
	if numZeros >= k-numOnes {
		return numOnes
	}
	return numOnes - (k - numOnes - numZeros)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kItemsWithMaximumSum(
    numOnes: number,
    numZeros: number,
    numNegOnes: number,
    k: number,
): number {
    if (numOnes >= k) {
        return k;
    }
    if (numZeros >= k - numOnes) {
        return numOnes;
    }
    return numOnes - (k - numOnes - numZeros);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn k_items_with_maximum_sum(
        num_ones: i32,
        num_zeros: i32,
        num_neg_ones: i32,
        k: i32,
    ) -> i32 {
        if num_ones > k {
            return k;
        }

        if num_ones + num_zeros > k {
            return num_ones;
        }

        num_ones - (k - num_ones - num_zeros)
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int KItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>袋子中装有一些物品，每个物品上都标记着数字 <code>1</code> 、<code>0</code> 或 <code>-1</code> 。</p>

<p>给你四个非负整数 <code>numOnes</code> 、<code>numZeros</code> 、<code>numNegOnes</code> 和 <code>k</code> 。</p>

<p>袋子最初包含：</p>

<ul>
	<li><code>numOnes</code> 件标记为 <code>1</code> 的物品。</li>
	<li><code>numZeros</code> 件标记为 <code>0</code> 的物品。</li>
	<li><code>numNegOnes</code> 件标记为 <code>-1</code> 的物品。</li>
</ul>

<p>现计划从这些物品中恰好选出 <code>k</code> 件物品。返回所有可行方案中，物品上所标记数字之和的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
<strong>输出：</strong>2
<strong>解释：</strong>袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 2 件标记为 1 的物品，得到的数字之和为 2 。
可以证明 2 是所有可行方案中的最大值。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
<strong>输出：</strong>3
<strong>解释：</strong>袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 3 件标记为 1 的物品，1 件标记为 0 的物品，得到的数字之和为 3 。
可以证明 3 是所有可行方案中的最大值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= numOnes, numZeros, numNegOnes &lt;= 50</code></li>
	<li><code>0 &lt;= k &lt;= numOnes + numZeros + numNegOnes</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们应该尽可能多地取标记为 $1$ 的物品，然后取标记为 $0$ 的物品，最后取标记为 $-1$ 的物品。

因此：

-   如果袋子中的物品标记为 $1$ 的数量大于等于 $k$，那么取 $k$ 件物品，数字之和为 $k$；
-   如果袋子中的物品标记为 $1$ 的数量小于 $k$，那么取 $\textit{numOnes}$ 件物品，数字之和为 $\textit{numOnes}$；如果标记为 $0$ 的物品数量大于等于 $k - \textit{numOnes}$，那么再取 $k - \textit{numOnes}$ 件物品，数字之和还是 $\textit{numOnes}$；
-   否则，我们再从标记为 $-1$ 的物品中取 $k - \textit{numOnes} - \textit{numZeros}$ 件物品，数字之和为 $\textit{numOnes} - (k - \textit{numOnes} - \textit{numZeros})$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kItemsWithMaximumSum(
        self, numOnes: int, numZeros: int, numNegOnes: int, k: int
    ) -> int:
        if numOnes >= k:
            return k
        if numZeros >= k - numOnes:
            return numOnes
        return numOnes - (k - numOnes - numZeros)
```

#### Java

```java
class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
};
```

#### Go

```go
func kItemsWithMaximumSum(numOnes int, numZeros int, numNegOnes int, k int) int {
	if numOnes >= k {
		return k
	}
	if numZeros >= k-numOnes {
		return numOnes
	}
	return numOnes - (k - numOnes - numZeros)
}
```

#### TypeScript

```ts
function kItemsWithMaximumSum(
    numOnes: number,
    numZeros: number,
    numNegOnes: number,
    k: number,
): number {
    if (numOnes >= k) {
        return k;
    }
    if (numZeros >= k - numOnes) {
        return numOnes;
    }
    return numOnes - (k - numOnes - numZeros);
}
```

#### Rust

```rust
impl Solution {
    pub fn k_items_with_maximum_sum(
        num_ones: i32,
        num_zeros: i32,
        num_neg_ones: i32,
        k: i32,
    ) -> i32 {
        if num_ones > k {
            return k;
        }

        if num_ones + num_zeros > k {
            return num_ones;
        }

        num_ones - (k - num_ones - num_zeros)
    }
}
```

#### C#

```cs
public class Solution {
    public int KItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) {
            return k;
        }
        if (numZeros >= k - numOnes) {
            return numOnes;
        }
        return numOnes - (k - numOnes - numZeros);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2601. 质数减法运算](https://leetcode.cn/problems/prime-subtraction-operation){#2601}

{{< tabs "2601" >}}

{{% tab "python" %}}
```python
class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        p = []
        for i in range(2, max(nums)):
            for j in p:
                if i % j == 0:
                    break
            else:
                p.append(i)

        n = len(nums)
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                continue
            j = bisect_right(p, nums[i] - nums[i + 1])
            if j == len(p) or p[j] >= nums[i]:
                return False
            nums[i] -= p[j]
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean primeSubOperation(int[] nums) {
        List<Integer> p = new ArrayList<>();
        for (int i = 2; i <= 1000; ++i) {
            boolean ok = true;
            for (int j : p) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                p.add(i);
            }
        }
        int n = nums.length;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = search(p, nums[i] - nums[i + 1]);
            if (j == p.size() || p.get(j) >= nums[i]) {
                return false;
            }
            nums[i] -= p.get(j);
        }
        return true;
    }

    private int search(List<Integer> nums, int x) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums.get(mid) > x) {
                r = mid;
            } else {
                l = mid + 1;
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
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        for (int i = 2; i <= 1000; ++i) {
            bool ok = true;
            for (int j : p) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                p.push_back(i);
            }
        }
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = upper_bound(p.begin(), p.end(), nums[i] - nums[i + 1]) - p.begin();
            if (j == p.size() || p[j] >= nums[i]) {
                return false;
            }
            nums[i] -= p[j];
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func primeSubOperation(nums []int) bool {
	p := []int{}
	for i := 2; i <= 1000; i++ {
		ok := true
		for _, j := range p {
			if i%j == 0 {
				ok = false
				break
			}
		}
		if ok {
			p = append(p, i)
		}
	}
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			continue
		}
		j := sort.SearchInts(p, nums[i]-nums[i+1]+1)
		if j == len(p) || p[j] >= nums[i] {
			return false
		}
		nums[i] -= p[j]
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function primeSubOperation(nums: number[]): boolean {
    const p: number[] = [];
    const max = Math.max(...nums);

    for (let i = 2; i < max; i++) {
        let isPrime = true;

        for (const x of p) {
            if (i % x === 0) {
                isPrime = false;
                break;
            }
        }

        while (isPrime && p.length <= i) {
            p.push(i);
        }
    }

    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) continue;

        const [x, next] = [nums[i], nums[i + 1]];
        const prime = p[x - next + 1];

        if (!prime || prime >= x) return false;
        nums[i] -= prime;
    }

    return true;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function primeSubOperation(nums) {
    const p = [];
    const max = Math.max(...nums);

    for (let i = 2; i < max; i++) {
        let isPrime = true;

        for (const x of p) {
            if (i % x === 0) {
                isPrime = false;
                break;
            }
        }

        while (isPrime && p.length <= i) {
            p.push(i);
        }
    }

    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) continue;

        const [x, next] = [nums[i], nums[i + 1]];
        const prime = p[x - next + 1];

        if (!prime || prime >= x) return false;
        nums[i] -= prime;
    }

    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p>你可以执行无限次下述运算：</p>

<ul>
	<li>选择一个之前未选过的下标 <code>i</code> ，并选择一个 <strong>严格小于</strong> <code>nums[i]</code> 的质数 <code>p</code> ，从 <code>nums[i]</code> 中减去 <code>p</code> 。</li>
</ul>

<p>如果你能通过上述运算使得 <code>nums</code> 成为严格递增数组，则返回 <code>true</code> ；否则返回 <code>false</code> 。</p>

<p><strong>严格递增数组</strong> 中的每个元素都严格大于其前面的元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,9,6,10]
<strong>输出：</strong>true
<strong>解释：</strong>
在第一次运算中：选择 i = 0 和 p = 3 ，然后从 nums[0] 减去 3 ，nums 变为 [1,9,6,10] 。
在第二次运算中：选择 i = 1 和 p = 7 ，然后从 nums[1] 减去 7 ，nums 变为 [1,2,6,10] 。
第二次运算后，nums 按严格递增顺序排序，因此答案为 true 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,8,11,12]
<strong>输出：</strong>true
<strong>解释：</strong>nums 从一开始就按严格递增顺序排序，因此不需要执行任何运算。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,8,3]
<strong>输出：</strong>false
<strong>解释：</strong>可以证明，执行运算无法使 nums 按严格递增顺序排序，因此答案是 false 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums.length == n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理质数 + 二分查找

我们先预处理得到 $1000$ 以内的所有质数，记录在数组 $p$ 中。

对于数组 $nums$ 中的每个元素 $nums[i]$，我们需要找到一个质数 $p[j]$，使得 p[j] \gt nums[i] - nums[i + 1]，并且 $p[j]$ 尽可能小。如果找不到这样的质数，说明无法通过减法运算使得 $nums$ 严格递增，返回 `false`。如果找到了这样的质数，我们就将 $nums[i]$ 减去 $p[j]$，并继续处理下一个元素。

如果 $nums$ 中的所有元素都处理完了，说明可以通过减法运算使得 $nums$ 严格递增，返回 `true`。

时间复杂度 $O(n \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        p = []
        for i in range(2, max(nums)):
            for j in p:
                if i % j == 0:
                    break
            else:
                p.append(i)

        n = len(nums)
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                continue
            j = bisect_right(p, nums[i] - nums[i + 1])
            if j == len(p) or p[j] >= nums[i]:
                return False
            nums[i] -= p[j]
        return True
```

#### Java

```java
class Solution {
    public boolean primeSubOperation(int[] nums) {
        List<Integer> p = new ArrayList<>();
        for (int i = 2; i <= 1000; ++i) {
            boolean ok = true;
            for (int j : p) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                p.add(i);
            }
        }
        int n = nums.length;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = search(p, nums[i] - nums[i + 1]);
            if (j == p.size() || p.get(j) >= nums[i]) {
                return false;
            }
            nums[i] -= p.get(j);
        }
        return true;
    }

    private int search(List<Integer> nums, int x) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums.get(mid) > x) {
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
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        for (int i = 2; i <= 1000; ++i) {
            bool ok = true;
            for (int j : p) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                p.push_back(i);
            }
        }
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int j = upper_bound(p.begin(), p.end(), nums[i] - nums[i + 1]) - p.begin();
            if (j == p.size() || p[j] >= nums[i]) {
                return false;
            }
            nums[i] -= p[j];
        }
        return true;
    }
};
```

#### Go

```go
func primeSubOperation(nums []int) bool {
	p := []int{}
	for i := 2; i <= 1000; i++ {
		ok := true
		for _, j := range p {
			if i%j == 0 {
				ok = false
				break
			}
		}
		if ok {
			p = append(p, i)
		}
	}
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			continue
		}
		j := sort.SearchInts(p, nums[i]-nums[i+1]+1)
		if j == len(p) || p[j] >= nums[i] {
			return false
		}
		nums[i] -= p[j]
	}
	return true
}
```

#### TypeScript

```ts
function primeSubOperation(nums: number[]): boolean {
    const p: number[] = [];
    for (let i = 2; i <= 1000; ++i) {
        let ok = true;
        for (const j of p) {
            if (i % j === 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            p.push(i);
        }
    }
    const search = (x: number): number => {
        let l = 0;
        let r = p.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (p[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const n = nums.length;
    for (let i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            continue;
        }
        const j = search(nums[i] - nums[i + 1]);
        if (j === p.length || p[j] >= nums[i]) {
            return false;
        }
        nums[i] -= p[j];
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理素数

<!-- tabs:start -->

#### TypeScript

```ts
function primeSubOperation(nums: number[]): boolean {
    const p: number[] = [];
    const max = Math.max(...nums);

    for (let i = 2; i < max; i++) {
        let isPrime = true;

        for (const x of p) {
            if (i % x === 0) {
                isPrime = false;
                break;
            }
        }

        while (isPrime && p.length <= i) {
            p.push(i);
        }
    }

    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) continue;

        const [x, next] = [nums[i], nums[i + 1]];
        const prime = p[x - next + 1];

        if (!prime || prime >= x) return false;
        nums[i] -= prime;
    }

    return true;
}
```

#### JavaScript

```js
function primeSubOperation(nums) {
    const p = [];
    const max = Math.max(...nums);

    for (let i = 2; i < max; i++) {
        let isPrime = true;

        for (const x of p) {
            if (i % x === 0) {
                isPrime = false;
                break;
            }
        }

        while (isPrime && p.length <= i) {
            p.push(i);
        }
    }

    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) continue;

        const [x, next] = [nums[i], nums[i + 1]];
        const prime = p[x - next + 1];

        if (!prime || prime >= x) return false;
        nums[i] -= prime;
    }

    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2602. 使数组元素全部相等的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal){#2602}

{{< tabs "2602" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        ans = []
        for x in queries:
            i = bisect_left(nums, x + 1)
            t = s[-1] - s[i] - (len(nums) - i) * x
            i = bisect_left(nums, x)
            t += x * i - s[i]
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Long> minOperations(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        List<Long> ans = new ArrayList<>();
        for (int x : queries) {
            int i = search(nums, x + 1);
            long t = s[n] - s[i] - 1L * (n - i) * x;
            i = search(nums, x);
            t += 1L * x * i - s[i];
            ans.add(t);
        }
        return ans;
    }

    private int search(int[] nums, int x) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        vector<long long> ans;
        for (auto& x : queries) {
            int i = lower_bound(nums.begin(), nums.end(), x + 1) - nums.begin();
            long long t = s[n] - s[i] - 1LL * (n - i) * x;
            i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            t += 1LL * x * i - s[i];
            ans.push_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, queries []int) (ans []int64) {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for _, x := range queries {
		i := sort.SearchInts(nums, x+1)
		t := s[n] - s[i] - (n-i)*x
		i = sort.SearchInts(nums, x)
		t += x*i - s[i]
		ans = append(ans, int64(t))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], queries: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    const search = (x: number): number => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const x of queries) {
        const i = search(x + 1);
        let t = s[n] - s[i] - (n - i) * x;
        const j = search(x);
        t += x * j - s[j];
        ans.push(t);
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

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>同时给你一个长度为 <code>m</code>&nbsp;的整数数组&nbsp;<code>queries</code>&nbsp;。第 <code>i</code>&nbsp;个查询中，你需要将 <code>nums</code>&nbsp;中所有元素变成&nbsp;<code>queries[i]</code>&nbsp;。你可以执行以下操作&nbsp;<strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>将数组里一个元素&nbsp;<strong>增大</strong>&nbsp;或者&nbsp;<strong>减小</strong>&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>请你返回一个长度为 <code>m</code>&nbsp;的数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是将&nbsp;<code>nums</code>&nbsp;中所有元素变成&nbsp;<code>queries[i]</code>&nbsp;的&nbsp;<strong>最少</strong>&nbsp;操作次数。</p>

<p><strong>注意</strong>，每次查询后，数组变回最开始的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,1,6,8], queries = [1,5]
<b>输出：</b>[14,10]
<b>解释：</b>第一个查询，我们可以执行以下操作：
- 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
- 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
- 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
第一个查询的总操作次数为 2 + 5 + 7 = 14 。
第二个查询，我们可以执行以下操作：
- 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
- 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
- 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
- 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,9,6,3], queries = [10]
<b>输出：</b>[20]
<b>解释：</b>我们可以将数组中所有元素都增大到 10 ，总操作次数为 8 + 1 + 4 + 7 = 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找

我们先将数组 $nums$ 进行排序，并计算出长度为 $n+1$ 的前缀和数组 $s$，其中 $s[i]$ 表示数组 $nums$ 中前 $i$ 个元素的和。

接下来，遍历每个查询 $queries[i]$，我们需要将所有大于 $queries[i]$ 的元素减小到 $queries[i]$，将所有小于 $queries[i]$ 的元素增大到 $queries[i]$。

我们可以通过二分查找找到数组 $nums$ 中第一个大于 $queries[i]$ 的元素的下标 $i$，则有 $n-i$ 个元素需要减小到 $queries[i]$，这些元素的和为 $s[n]-s[i]$，这些元素的和需要减去 $n-i$ 个 $queries[i]$，因此，这些元素减小到 $queries[i]$ 的总操作次数为 $s[n]-s[i]-(n-i)\times queries[i]$。

同理，我们可以找到数组 $nums$ 中第一个大于等于 $queries[i]$ 的元素的下标 $i$，则有 $i$ 个元素需要增大到 $queries[i]$，这些元素的和为 $s[i]$，因此，这些元素增大到 $queries[i]$ 的总操作次数为 $queries[i]\times i-s[i]$。

最后，将这两个总操作次数相加，即为将数组 $nums$ 中所有元素变成 $queries[i]$ 的最少操作次数，即 $ans[i]=s[n]-s[i]-(n-i)\times queries[i]+queries[i]\times i-s[i]$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        ans = []
        for x in queries:
            i = bisect_left(nums, x + 1)
            t = s[-1] - s[i] - (len(nums) - i) * x
            i = bisect_left(nums, x)
            t += x * i - s[i]
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public List<Long> minOperations(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        List<Long> ans = new ArrayList<>();
        for (int x : queries) {
            int i = search(nums, x + 1);
            long t = s[n] - s[i] - 1L * (n - i) * x;
            i = search(nums, x);
            t += 1L * x * i - s[i];
            ans.add(t);
        }
        return ans;
    }

    private int search(int[] nums, int x) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        vector<long long> ans;
        for (auto& x : queries) {
            int i = lower_bound(nums.begin(), nums.end(), x + 1) - nums.begin();
            long long t = s[n] - s[i] - 1LL * (n - i) * x;
            i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            t += 1LL * x * i - s[i];
            ans.push_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int, queries []int) (ans []int64) {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for _, x := range queries {
		i := sort.SearchInts(nums, x+1)
		t := s[n] - s[i] - (n-i)*x
		i = sort.SearchInts(nums, x)
		t += x*i - s[i]
		ans = append(ans, int64(t))
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[], queries: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    const search = (x: number): number => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const x of queries) {
        const i = search(x + 1);
        let t = s[n] - s[i] - (n - i) * x;
        const j = search(x);
        t += x * j - s[j];
        ans.push(t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2603. 收集树中金币](https://leetcode.cn/problems/collect-coins-in-a-tree){#2603}

{{< tabs "2603" >}}

{{% tab "python" %}}
```python
class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        n = len(coins)
        q = deque(i for i in range(n) if len(g[i]) == 1 and coins[i] == 0)
        while q:
            i = q.popleft()
            for j in g[i]:
                g[j].remove(i)
                if coins[j] == 0 and len(g[j]) == 1:
                    q.append(j)
            g[i].clear()
        for k in range(2):
            q = [i for i in range(n) if len(g[i]) == 1]
            for i in q:
                for j in g[i]:
                    g[j].remove(i)
                g[i].clear()
        return sum(len(g[a]) > 0 and len(g[b]) > 0 for a, b in edges) * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int collectTheCoins(int[] coins, int[][] edges) {
        int n = coins.length;
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && g[i].size() == 1) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                g[j].remove(i);
                if (coins[j] == 0 && g[j].size() == 1) {
                    q.offer(j);
                }
            }
            g[i].clear();
        }
        q.clear();
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < n; ++i) {
                if (g[i].size() == 1) {
                    q.offer(i);
                }
            }
            for (int i : q) {
                for (int j : g[i]) {
                    g[j].remove(i);
                }
                g[i].clear();
            }
        }
        int ans = 0;
        for (var e : edges) {
            int a = e[0], b = e[1];
            if (g[a].size() > 0 && g[b].size() > 0) {
                ans += 2;
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
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        unordered_set<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && g[i].size() == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                g[j].erase(i);
                if (coins[j] == 0 && g[j].size() == 1) {
                    q.push(j);
                }
            }
            g[i].clear();
        }
        for (int k = 0; k < 2; ++k) {
            vector<int> q;
            for (int i = 0; i < n; ++i) {
                if (g[i].size() == 1) {
                    q.push_back(i);
                }
            }
            for (int i : q) {
                for (int j : g[i]) {
                    g[j].erase(i);
                }
                g[i].clear();
            }
        }
        int ans = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (g[a].size() && g[b].size()) {
                ans += 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func collectTheCoins(coins []int, edges [][]int) int {
	n := len(coins)
	g := make([]map[int]bool, n)
	for i := range g {
		g[i] = map[int]bool{}
	}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a][b] = true
		g[b][a] = true
	}
	q := []int{}
	for i, c := range coins {
		if c == 0 && len(g[i]) == 1 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for j := range g[i] {
			delete(g[j], i)
			if coins[j] == 0 && len(g[j]) == 1 {
				q = append(q, j)
			}
		}
		g[i] = map[int]bool{}
	}
	for k := 0; k < 2; k++ {
		q := []int{}
		for i := range coins {
			if len(g[i]) == 1 {
				q = append(q, i)
			}
		}
		for _, i := range q {
			for j := range g[i] {
				delete(g[j], i)
			}
			g[i] = map[int]bool{}
		}
	}
	ans := 0
	for _, e := range edges {
		a, b := e[0], e[1]
		if len(g[a]) > 0 && len(g[b]) > 0 {
			ans += 2
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function collectTheCoins(coins: number[], edges: number[][]): number {
    const n = coins.length;
    const g: Set<number>[] = new Array(n).fill(0).map(() => new Set<number>());
    for (const [a, b] of edges) {
        g[a].add(b);
        g[b].add(a);
    }
    let q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (coins[i] === 0 && g[i].size === 1) {
            q.push(i);
        }
    }
    while (q.length) {
        const i = q.pop()!;
        for (const j of g[i]) {
            g[j].delete(i);
            if (coins[j] === 0 && g[j].size === 1) {
                q.push(j);
            }
        }
        g[i].clear();
    }
    q = [];
    for (let k = 0; k < 2; ++k) {
        for (let i = 0; i < n; ++i) {
            if (g[i].size === 1) {
                q.push(i);
            }
        }
        for (const i of q) {
            for (const j of g[i]) {
                g[j].delete(i);
            }
            g[i].clear();
        }
    }
    let ans = 0;
    for (const [a, b] of edges) {
        if (g[a].size > 0 && g[b].size > 0) {
            ans += 2;
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

<p>给你一个 <code>n</code>&nbsp;个节点的无向无根树，节点编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。给你整数&nbsp;<code>n</code>&nbsp;和一个长度为 <code>n - 1</code>&nbsp;的二维整数数组 <code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。再给你一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>coins</code>&nbsp;，其中&nbsp;<code>coins[i]</code> 可能为&nbsp;<code>0</code>&nbsp;也可能为&nbsp;<code>1</code>&nbsp;，<code>1</code>&nbsp;表示节点 <code>i</code>&nbsp;处有一个金币。</p>

<p>一开始，你需要选择树中任意一个节点出发。你可以执行下述操作任意次：</p>

<ul>
	<li>收集距离当前节点距离为 <code>2</code>&nbsp;以内的所有金币，或者</li>
	<li>移动到树中一个相邻节点。</li>
</ul>

<p>你需要收集树中所有的金币，并且回到出发节点，请你返回最少经过的边数。</p>

<p>如果你多次经过一条边，每一次经过都会给答案加一。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2603.Collect%20Coins%20in%20a%20Tree/images/graph-2.png" style="width: 522px; height: 522px;"></p>

<pre><b>输入：</b>coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
<b>输出：</b>2
<b>解释：</b>从节点 2 出发，收集节点 0 处的金币，移动到节点 3 ，收集节点 5 处的金币，然后移动回节点 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2603.Collect%20Coins%20in%20a%20Tree/images/graph-4.png" style="width: 522px; height: 522px;"></p>

<pre><b>输入：</b>coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]
<b>输出：</b>2
<b>解释：</b>从节点 0 出发，收集节点 4 和 3 处的金币，移动到节点 2 处，收集节点 7 处的金币，移动回节点 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == coins.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= coins[i] &lt;= 1</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code>&nbsp;表示一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们先将 $edges$ 中的边转换成邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻接节点，用集合表示。

接下来我们遍历所有节点，找到 $coins[i]=0$ 且 $g[i]$ 中只有一个节点的节点（也即是金币为 $0$ 的叶子节点），将其加入队列 $q$ 中。

然后我们不断地从队列中取出节点，将其从邻接表中删除，然后判断其邻接节点是否满足 $coins[j]=0$ 且 $g[j]$ 中只有一个节点的条件，如果满足则将其加入队列 $q$ 中。循环，直至队列为空。

经过上述操作后，我们得到了一棵新的树，且树的叶子节点都是金币为 $1$ 的节点。

然后，我们再删除剩下的两层叶子节点，最终得到的是一棵所有节点都需要被访问的节点，我们只需要统计其边数，乘上 $2$，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

相似题目：

-   [2204. 无向图中到环的距离](https://github.com/doocs/leetcode/blob/main/solution/2200-2299/2204.Distance%20to%20a%20Cycle%20in%20Undirected%20Graph/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        n = len(coins)
        q = deque(i for i in range(n) if len(g[i]) == 1 and coins[i] == 0)
        while q:
            i = q.popleft()
            for j in g[i]:
                g[j].remove(i)
                if coins[j] == 0 and len(g[j]) == 1:
                    q.append(j)
            g[i].clear()
        for k in range(2):
            q = [i for i in range(n) if len(g[i]) == 1]
            for i in q:
                for j in g[i]:
                    g[j].remove(i)
                g[i].clear()
        return sum(len(g[a]) > 0 and len(g[b]) > 0 for a, b in edges) * 2
```

#### Java

```java
class Solution {
    public int collectTheCoins(int[] coins, int[][] edges) {
        int n = coins.length;
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && g[i].size() == 1) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                g[j].remove(i);
                if (coins[j] == 0 && g[j].size() == 1) {
                    q.offer(j);
                }
            }
            g[i].clear();
        }
        q.clear();
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < n; ++i) {
                if (g[i].size() == 1) {
                    q.offer(i);
                }
            }
            for (int i : q) {
                for (int j : g[i]) {
                    g[j].remove(i);
                }
                g[i].clear();
            }
        }
        int ans = 0;
        for (var e : edges) {
            int a = e[0], b = e[1];
            if (g[a].size() > 0 && g[b].size() > 0) {
                ans += 2;
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
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        unordered_set<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && g[i].size() == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                g[j].erase(i);
                if (coins[j] == 0 && g[j].size() == 1) {
                    q.push(j);
                }
            }
            g[i].clear();
        }
        for (int k = 0; k < 2; ++k) {
            vector<int> q;
            for (int i = 0; i < n; ++i) {
                if (g[i].size() == 1) {
                    q.push_back(i);
                }
            }
            for (int i : q) {
                for (int j : g[i]) {
                    g[j].erase(i);
                }
                g[i].clear();
            }
        }
        int ans = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (g[a].size() && g[b].size()) {
                ans += 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func collectTheCoins(coins []int, edges [][]int) int {
	n := len(coins)
	g := make([]map[int]bool, n)
	for i := range g {
		g[i] = map[int]bool{}
	}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a][b] = true
		g[b][a] = true
	}
	q := []int{}
	for i, c := range coins {
		if c == 0 && len(g[i]) == 1 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for j := range g[i] {
			delete(g[j], i)
			if coins[j] == 0 && len(g[j]) == 1 {
				q = append(q, j)
			}
		}
		g[i] = map[int]bool{}
	}
	for k := 0; k < 2; k++ {
		q := []int{}
		for i := range coins {
			if len(g[i]) == 1 {
				q = append(q, i)
			}
		}
		for _, i := range q {
			for j := range g[i] {
				delete(g[j], i)
			}
			g[i] = map[int]bool{}
		}
	}
	ans := 0
	for _, e := range edges {
		a, b := e[0], e[1]
		if len(g[a]) > 0 && len(g[b]) > 0 {
			ans += 2
		}
	}
	return ans
}
```

#### TypeScript

```ts
function collectTheCoins(coins: number[], edges: number[][]): number {
    const n = coins.length;
    const g: Set<number>[] = new Array(n).fill(0).map(() => new Set<number>());
    for (const [a, b] of edges) {
        g[a].add(b);
        g[b].add(a);
    }
    let q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (coins[i] === 0 && g[i].size === 1) {
            q.push(i);
        }
    }
    while (q.length) {
        const i = q.pop()!;
        for (const j of g[i]) {
            g[j].delete(i);
            if (coins[j] === 0 && g[j].size === 1) {
                q.push(j);
            }
        }
        g[i].clear();
    }
    q = [];
    for (let k = 0; k < 2; ++k) {
        for (let i = 0; i < n; ++i) {
            if (g[i].size === 1) {
                q.push(i);
            }
        }
        for (const i of q) {
            for (const j of g[i]) {
                g[j].delete(i);
            }
            g[i].clear();
        }
    }
    let ans = 0;
    for (const [a, b] of edges) {
        if (g[a].size > 0 && g[b].size > 0) {
            ans += 2;
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

# [2604. 吃掉所有谷子的最短时间 🔒](https://leetcode.cn/problems/minimum-time-to-eat-all-grains){#2604}

{{< tabs "2604" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, hens: List[int], grains: List[int]) -> int:
        def check(t):
            j = 0
            for x in hens:
                if j == m:
                    return True
                y = grains[j]
                if y <= x:
                    d = x - y
                    if d > t:
                        return False
                    while j < m and grains[j] <= x:
                        j += 1
                    while j < m and min(d, grains[j] - x) + grains[j] - y <= t:
                        j += 1
                else:
                    while j < m and grains[j] - x <= t:
                        j += 1
            return j == m

        hens.sort()
        grains.sort()
        m = len(grains)
        r = abs(hens[0] - grains[0]) + grains[-1] - grains[0] + 1
        return bisect_left(range(r), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] hens;
    private int[] grains;
    private int m;

    public int minimumTime(int[] hens, int[] grains) {
        m = grains.length;
        this.hens = hens;
        this.grains = grains;
        Arrays.sort(hens);
        Arrays.sort(grains);
        int l = 0;
        int r = Math.abs(hens[0] - grains[0]) + grains[m - 1] - grains[0];
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int t) {
        int j = 0;
        for (int x : hens) {
            if (j == m) {
                return true;
            }
            int y = grains[j];
            if (y <= x) {
                int d = x - y;
                if (d > t) {
                    return false;
                }
                while (j < m && grains[j] <= x) {
                    ++j;
                }
                while (j < m && Math.min(d, grains[j] - x) + grains[j] - y <= t) {
                    ++j;
                }
            } else {
                while (j < m && grains[j] - x <= t) {
                    ++j;
                }
            }
        }
        return j == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        int m = grains.size();
        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());
        int l = 0;
        int r = abs(hens[0] - grains[0]) + grains[m - 1] - grains[0];
        auto check = [&](int t) -> bool {
            int j = 0;
            for (int x : hens) {
                if (j == m) {
                    return true;
                }
                int y = grains[j];
                if (y <= x) {
                    int d = x - y;
                    if (d > t) {
                        return false;
                    }
                    while (j < m && grains[j] <= x) {
                        ++j;
                    }
                    while (j < m && min(d, grains[j] - x) + grains[j] - y <= t) {
                        ++j;
                    }
                } else {
                    while (j < m && grains[j] - x <= t) {
                        ++j;
                    }
                }
            }
            return j == m;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(hens []int, grains []int) int {
	sort.Ints(hens)
	sort.Ints(grains)
	m := len(grains)
	l, r := 0, abs(hens[0]-grains[0])+grains[m-1]-grains[0]
	check := func(t int) bool {
		j := 0
		for _, x := range hens {
			if j == m {
				return true
			}
			y := grains[j]
			if y <= x {
				d := x - y
				if d > t {
					return false
				}
				for j < m && grains[j] <= x {
					j++
				}
				for j < m && min(d, grains[j]-x)+grains[j]-y <= t {
					j++
				}
			} else {
				for j < m && grains[j]-x <= t {
					j++
				}
			}
		}
		return j == m
	}
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
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
function minimumTime(hens: number[], grains: number[]): number {
    hens.sort((a, b) => a - b);
    grains.sort((a, b) => a - b);
    const m = grains.length;
    let l = 0;
    let r = Math.abs(hens[0] - grains[0]) + grains[m - 1] - grains[0] + 1;

    const check = (t: number): boolean => {
        let j = 0;
        for (const x of hens) {
            if (j === m) {
                return true;
            }
            const y = grains[j];
            if (y <= x) {
                const d = x - y;
                if (d > t) {
                    return false;
                }
                while (j < m && grains[j] <= x) {
                    ++j;
                }
                while (j < m && Math.min(d, grains[j] - x) + grains[j] - y <= t) {
                    ++j;
                }
            } else {
                while (j < m && grains[j] - x <= t) {
                    ++j;
                }
            }
        }
        return j === m;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一条线上有 <code>n</code> 只母鸡和 <code>m</code> 颗谷子。给定两个整数数组 <code>hens</code> 和 <code>grains</code> ，它们的大小分别为 <code>n</code> 和 <code>m</code> ，表示母鸡和谷子的初始位置。</p>

<p>如果一只母鸡和一颗谷子在同一个位置，那么这只母鸡可以吃掉这颗谷子。吃掉一颗谷子的时间可以忽略不计。一只母鸡也可以吃掉多颗谷子。</p>

<p>在 <code>1</code> 秒钟内，一只母鸡可以向左或向右移动 <code>1</code> 个单位。母鸡可以同时且独立地移动。</p>

<p>如果母鸡行动得当，返回吃掉所有谷子的 <strong>最短</strong> 时间。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>hens = [3,6,7], grains = [2,4,7,9]
<b>输出：</b>2
<b>解释：</b>
母鸡吃掉所有谷子的一种方法如下：
- 第一只母鸡在 1 秒钟内吃掉位置 2 处的谷子。
- 第二只母鸡在 2 秒钟内吃掉位置 4 处的谷子。
- 第三只母鸡在 2 秒钟内吃掉位置 7 和 9 处的谷子。 
所以，需要的最长时间为2秒。 
可以证明，在2秒钟之前，母鸡不能吃掉所有谷子。</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>hens = [4,6,109,111,213,215], grains = [5,110,214]
<b>输出：</b>1
<b>解释：</b>
母鸡吃掉所有谷子的一种方法如下：
- 第一只母鸡在 1 秒钟内吃掉位置 5 处的谷子。
- 第四只母鸡在 1 秒钟内吃掉位置 110 处的谷子。
- 第六只母鸡在 1 秒钟内吃掉位置 214 处的谷子。
- 其他母鸡不动。 
所以，需要的最长时间为 1 秒。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hens.length, grains.length &lt;= 2*10<sup>4</sup></code></li>
	<li><code>0 &lt;= hens[i], grains[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们先将鸡和谷物按照位置从小到大排序，接下来二分枚举时间 $t$，找到一个最小的 $t$ 使得所有谷物能在 $t$ 秒内被吃完。

对于每个鸡，我们用指针 $j$ 指向当前还未被吃的谷物中最左边的谷物，记当前鸡的位置为 $x$，谷物的位置为 $y$，则有以下几种情况：

-   如果 $y \leq x$，我们记 $d = x - y$，如果 $d \gt t$，那么当前谷物无法被吃掉，直接返回 `false`。否则，我们向右移动指针 $j$，直到 $j=m$ 或者 $grains[j] \gt x$。此时我们需要判断鸡是否能吃到 $j$ 指向的谷物，如果能吃到，我们继续向右移动指针 $j$，直到 $j=m$ 或者 $min(d, grains[j] - x) + grains[j] - y \gt t$。
-   如果 $y \lt x$，我们向右移动指针 $j$，直到 $j=m$ 或者 $grains[j] - x \gt t$。

如果 $j=m$，说明所有谷物都被吃完了，返回 `true`，否则返回 `false`。

时间复杂度 $O(n \times \log n + m \times \log m + (m + n) \times \log U)$，空间复杂度 $O(\log m + \log n)$。其中 $n$ 和 $m$ 分别为鸡和谷物的数量，而 $U$ 为所有鸡和谷物的位置的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, hens: List[int], grains: List[int]) -> int:
        def check(t):
            j = 0
            for x in hens:
                if j == m:
                    return True
                y = grains[j]
                if y <= x:
                    d = x - y
                    if d > t:
                        return False
                    while j < m and grains[j] <= x:
                        j += 1
                    while j < m and min(d, grains[j] - x) + grains[j] - y <= t:
                        j += 1
                else:
                    while j < m and grains[j] - x <= t:
                        j += 1
            return j == m

        hens.sort()
        grains.sort()
        m = len(grains)
        r = abs(hens[0] - grains[0]) + grains[-1] - grains[0] + 1
        return bisect_left(range(r), True, key=check)
```

#### Java

```java
class Solution {
    private int[] hens;
    private int[] grains;
    private int m;

    public int minimumTime(int[] hens, int[] grains) {
        m = grains.length;
        this.hens = hens;
        this.grains = grains;
        Arrays.sort(hens);
        Arrays.sort(grains);
        int l = 0;
        int r = Math.abs(hens[0] - grains[0]) + grains[m - 1] - grains[0];
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int t) {
        int j = 0;
        for (int x : hens) {
            if (j == m) {
                return true;
            }
            int y = grains[j];
            if (y <= x) {
                int d = x - y;
                if (d > t) {
                    return false;
                }
                while (j < m && grains[j] <= x) {
                    ++j;
                }
                while (j < m && Math.min(d, grains[j] - x) + grains[j] - y <= t) {
                    ++j;
                }
            } else {
                while (j < m && grains[j] - x <= t) {
                    ++j;
                }
            }
        }
        return j == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        int m = grains.size();
        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());
        int l = 0;
        int r = abs(hens[0] - grains[0]) + grains[m - 1] - grains[0];
        auto check = [&](int t) -> bool {
            int j = 0;
            for (int x : hens) {
                if (j == m) {
                    return true;
                }
                int y = grains[j];
                if (y <= x) {
                    int d = x - y;
                    if (d > t) {
                        return false;
                    }
                    while (j < m && grains[j] <= x) {
                        ++j;
                    }
                    while (j < m && min(d, grains[j] - x) + grains[j] - y <= t) {
                        ++j;
                    }
                } else {
                    while (j < m && grains[j] - x <= t) {
                        ++j;
                    }
                }
            }
            return j == m;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
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
func minimumTime(hens []int, grains []int) int {
	sort.Ints(hens)
	sort.Ints(grains)
	m := len(grains)
	l, r := 0, abs(hens[0]-grains[0])+grains[m-1]-grains[0]
	check := func(t int) bool {
		j := 0
		for _, x := range hens {
			if j == m {
				return true
			}
			y := grains[j]
			if y <= x {
				d := x - y
				if d > t {
					return false
				}
				for j < m && grains[j] <= x {
					j++
				}
				for j < m && min(d, grains[j]-x)+grains[j]-y <= t {
					j++
				}
			} else {
				for j < m && grains[j]-x <= t {
					j++
				}
			}
		}
		return j == m
	}
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
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
function minimumTime(hens: number[], grains: number[]): number {
    hens.sort((a, b) => a - b);
    grains.sort((a, b) => a - b);
    const m = grains.length;
    let l = 0;
    let r = Math.abs(hens[0] - grains[0]) + grains[m - 1] - grains[0] + 1;

    const check = (t: number): boolean => {
        let j = 0;
        for (const x of hens) {
            if (j === m) {
                return true;
            }
            const y = grains[j];
            if (y <= x) {
                const d = x - y;
                if (d > t) {
                    return false;
                }
                while (j < m && grains[j] <= x) {
                    ++j;
                }
                while (j < m && Math.min(d, grains[j] - x) + grains[j] - y <= t) {
                    ++j;
                }
            } else {
                while (j < m && grains[j] - x <= t) {
                    ++j;
                }
            }
        }
        return j === m;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2605. 从两个数字数组里生成最小数字](https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays){#2605}

{{< tabs "2605" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        mask1 = mask2 = 0
        for x in nums1:
            mask1 |= 1 << x
        for x in nums2:
            mask2 |= 1 << x
        mask = mask1 & mask2
        if mask:
            return (mask & -mask).bit_length() - 1
        a = (mask1 & -mask1).bit_length() - 1
        b = (mask2 & -mask2).bit_length() - 1
        return min(a * 10 + b, b * 10 + a)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask != 0) {
            return Integer.numberOfTrailingZeros(mask);
        }
        int a = Integer.numberOfTrailingZeros(mask1);
        int b = Integer.numberOfTrailingZeros(mask2);
        return Math.min(a * 10 + b, b * 10 + a);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask) {
            return __builtin_ctz(mask);
        }
        int a = __builtin_ctz(mask1);
        int b = __builtin_ctz(mask2);
        return min(a * 10 + b, b * 10 + a);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumber(nums1 []int, nums2 []int) int {
	var mask1, mask2 uint
	for _, x := range nums1 {
		mask1 |= 1 << x
	}
	for _, x := range nums2 {
		mask2 |= 1 << x
	}
	if mask := mask1 & mask2; mask != 0 {
		return bits.TrailingZeros(mask)
	}
	a, b := bits.TrailingZeros(mask1), bits.TrailingZeros(mask2)
	return min(a*10+b, b*10+a)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumber(nums1: number[], nums2: number[]): number {
    let mask1: number = 0;
    let mask2: number = 0;
    for (const x of nums1) {
        mask1 |= 1 << x;
    }
    for (const x of nums2) {
        mask2 |= 1 << x;
    }
    const mask = mask1 & mask2;
    if (mask !== 0) {
        return numberOfTrailingZeros(mask);
    }
    const a = numberOfTrailingZeros(mask1);
    const b = numberOfTrailingZeros(mask2);
    return Math.min(a * 10 + b, b * 10 + a);
}

function numberOfTrailingZeros(i: number): number {
    let y = 0;
    if (i === 0) {
        return 32;
    }
    let n = 31;
    y = i << 16;
    if (y != 0) {
        n = n - 16;
        i = y;
    }
    y = i << 8;
    if (y != 0) {
        n = n - 8;
        i = y;
    }
    y = i << 4;
    if (y != 0) {
        n = n - 4;
        i = y;
    }
    y = i << 2;
    if (y != 0) {
        n = n - 2;
        i = y;
    }
    return n - ((i << 1) >>> 31);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut h1: HashMap<i32, bool> = HashMap::new();

        for &n in &nums1 {
            h1.insert(n, true);
        }

        let mut h2: HashMap<i32, bool> = HashMap::new();
        for &n in &nums2 {
            h2.insert(n, true);
        }

        let mut a = 0;
        let mut b = 0;
        for i in 1..10 {
            if h1.contains_key(&i) && h2.contains_key(&i) {
                return i;
            }

            if a == 0 && h1.contains_key(&i) {
                a = i;
            }

            if b == 0 && h2.contains_key(&i) {
                b = i;
            }
        }

        std::cmp::min(a * 10 + b, b * 10 + a)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你两个只包含 1 到 9 之间数字的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，每个数组中的元素 <strong>互不相同</strong>&nbsp;，请你返回 <strong>最小</strong> 的数字，两个数组都 <strong>至少</strong> 包含这个数字的某个数位。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [4,1,3], nums2 = [5,7]
<b>输出：</b>15
<b>解释：</b>数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [3,5,2,6], nums2 = [3,1,7]
<b>输出：</b>3
<b>解释：</b>数字 3 的数位 3 在两个数组中都出现了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 9</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 9</code></li>
	<li>每个数组中，元素 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们观察发现，如果数组 $nums1$ 和 $nums2$ 中有相同的数字，那么相同数字中的最小值一定是最小的数字。否则我们取 $nums1$ 中的数字 $a$ 和 $nums2$ 中的数字 $b$，将 $a$ 和 $b$ 拼接成两个数字，取其中较小的数字即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 100
        for a in nums1:
            for b in nums2:
                if a == b:
                    ans = min(ans, a)
                else:
                    ans = min(ans, 10 * a + b, 10 * b + a)
        return ans
```

#### Java

```java
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int ans = 100;
        for (int a : nums1) {
            for (int b : nums2) {
                if (a == b) {
                    ans = Math.min(ans, a);
                } else {
                    ans = Math.min(ans, Math.min(a * 10 + b, b * 10 + a));
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
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int ans = 100;
        for (int a : nums1) {
            for (int b : nums2) {
                if (a == b) {
                    ans = min(ans, a);
                } else {
                    ans = min({ans, a * 10 + b, b * 10 + a});
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minNumber(nums1 []int, nums2 []int) int {
	ans := 100
	for _, a := range nums1 {
		for _, b := range nums2 {
			if a == b {
				ans = min(ans, a)
			} else {
				ans = min(ans, min(a*10+b, b*10+a))
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minNumber(nums1: number[], nums2: number[]): number {
    let ans = 100;
    for (const a of nums1) {
        for (const b of nums2) {
            if (a === b) {
                ans = Math.min(ans, a);
            } else {
                ans = Math.min(ans, a * 10 + b, b * 10 + a);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut ans = 100;

        for &a in &nums1 {
            for &b in &nums2 {
                if a == b {
                    ans = std::cmp::min(ans, a);
                } else {
                    ans = std::cmp::min(ans, std::cmp::min(a * 10 + b, b * 10 + a));
                }
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表或数组 + 枚举

我们可以用哈希表或数组记录数组 $nums1$ 和 $nums2$ 中的数字，然后枚举 $1 \sim 9$，如果 $i$ 在两个数组中都出现了，那么 $i$ 就是最小的数字。否则我们取 $nums1$ 中的数字 $a$ 和 $nums2$ 中的数字 $b$，将 $a$ 和 $b$ 拼接成两个数字，取其中较小的数字即可。

时间复杂度 $(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度；而 $C$ 是数组 $nums1$ 和 $nums2$ 中数字的范围，本题中 $C = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums1) & set(nums2)
        if s:
            return min(s)
        a, b = min(nums1), min(nums2)
        return min(a * 10 + b, b * 10 + a)
```

#### Java

```java
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        boolean[] s1 = new boolean[10];
        boolean[] s2 = new boolean[10];
        for (int x : nums1) {
            s1[x] = true;
        }
        for (int x : nums2) {
            s2[x] = true;
        }
        int a = 0, b = 0;
        for (int i = 1; i < 10; ++i) {
            if (s1[i] && s2[i]) {
                return i;
            }
            if (a == 0 && s1[i]) {
                a = i;
            }
            if (b == 0 && s2[i]) {
                b = i;
            }
        }
        return Math.min(a * 10 + b, b * 10 + a);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bitset<10> s1;
        bitset<10> s2;
        for (int x : nums1) {
            s1[x] = 1;
        }
        for (int x : nums2) {
            s2[x] = 1;
        }
        int a = 0, b = 0;
        for (int i = 1; i < 10; ++i) {
            if (s1[i] && s2[i]) {
                return i;
            }
            if (!a && s1[i]) {
                a = i;
            }
            if (!b && s2[i]) {
                b = i;
            }
        }
        return min(a * 10 + b, b * 10 + a);
    }
};
```

#### Go

```go
func minNumber(nums1 []int, nums2 []int) int {
	s1 := [10]bool{}
	s2 := [10]bool{}
	for _, x := range nums1 {
		s1[x] = true
	}
	for _, x := range nums2 {
		s2[x] = true
	}
	a, b := 0, 0
	for i := 1; i < 10; i++ {
		if s1[i] && s2[i] {
			return i
		}
		if a == 0 && s1[i] {
			a = i
		}
		if b == 0 && s2[i] {
			b = i
		}
	}
	return min(a*10+b, b*10+a)
}
```

#### TypeScript

```ts
function minNumber(nums1: number[], nums2: number[]): number {
    const s1: boolean[] = new Array(10).fill(false);
    const s2: boolean[] = new Array(10).fill(false);
    for (const x of nums1) {
        s1[x] = true;
    }
    for (const x of nums2) {
        s2[x] = true;
    }
    let a = 0;
    let b = 0;
    for (let i = 1; i < 10; ++i) {
        if (s1[i] && s2[i]) {
            return i;
        }
        if (a === 0 && s1[i]) {
            a = i;
        }
        if (b === 0 && s2[i]) {
            b = i;
        }
    }
    return Math.min(a * 10 + b, b * 10 + a);
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut h1: HashMap<i32, bool> = HashMap::new();

        for &n in &nums1 {
            h1.insert(n, true);
        }

        let mut h2: HashMap<i32, bool> = HashMap::new();
        for &n in &nums2 {
            h2.insert(n, true);
        }

        let mut a = 0;
        let mut b = 0;
        for i in 1..10 {
            if h1.contains_key(&i) && h2.contains_key(&i) {
                return i;
            }

            if a == 0 && h1.contains_key(&i) {
                a = i;
            }

            if b == 0 && h2.contains_key(&i) {
                b = i;
            }
        }

        std::cmp::min(a * 10 + b, b * 10 + a)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：位运算

由于数字的范围是 $1 \sim 9$，我们可以用一个长度为 $10$ 的二进制数来表示数组 $nums1$ 和 $nums2$ 中的数字。我们用 $mask1$ 表示数组 $nums1$ 中的数字，用 $mask2$ 表示数组 $nums2$ 中的数字。

如果 $mask1$ 和 $mask2$ 进行按位与得到的数字 $mask$ 不等于 $0$，那么我们提取 $mask$ 中最后一位 $1$ 所在的位置，即为最小的数字。

否则，我们分别提取 $mask1$ 和 $mask2$ 中最后一位 $1$ 所在的位置，分别记为 $a$ 和 $b$，那么最小的数字就是 $min(a \times 10 + b, b \times 10 + a)$。

时间复杂度 $O(m + n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        mask1 = mask2 = 0
        for x in nums1:
            mask1 |= 1 << x
        for x in nums2:
            mask2 |= 1 << x
        mask = mask1 & mask2
        if mask:
            return (mask & -mask).bit_length() - 1
        a = (mask1 & -mask1).bit_length() - 1
        b = (mask2 & -mask2).bit_length() - 1
        return min(a * 10 + b, b * 10 + a)
```

#### Java

```java
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask != 0) {
            return Integer.numberOfTrailingZeros(mask);
        }
        int a = Integer.numberOfTrailingZeros(mask1);
        int b = Integer.numberOfTrailingZeros(mask2);
        return Math.min(a * 10 + b, b * 10 + a);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask) {
            return __builtin_ctz(mask);
        }
        int a = __builtin_ctz(mask1);
        int b = __builtin_ctz(mask2);
        return min(a * 10 + b, b * 10 + a);
    }
};
```

#### Go

```go
func minNumber(nums1 []int, nums2 []int) int {
	var mask1, mask2 uint
	for _, x := range nums1 {
		mask1 |= 1 << x
	}
	for _, x := range nums2 {
		mask2 |= 1 << x
	}
	if mask := mask1 & mask2; mask != 0 {
		return bits.TrailingZeros(mask)
	}
	a, b := bits.TrailingZeros(mask1), bits.TrailingZeros(mask2)
	return min(a*10+b, b*10+a)
}
```

#### TypeScript

```ts
function minNumber(nums1: number[], nums2: number[]): number {
    let mask1: number = 0;
    let mask2: number = 0;
    for (const x of nums1) {
        mask1 |= 1 << x;
    }
    for (const x of nums2) {
        mask2 |= 1 << x;
    }
    const mask = mask1 & mask2;
    if (mask !== 0) {
        return numberOfTrailingZeros(mask);
    }
    const a = numberOfTrailingZeros(mask1);
    const b = numberOfTrailingZeros(mask2);
    return Math.min(a * 10 + b, b * 10 + a);
}

function numberOfTrailingZeros(i: number): number {
    let y = 0;
    if (i === 0) {
        return 32;
    }
    let n = 31;
    y = i << 16;
    if (y != 0) {
        n = n - 16;
        i = y;
    }
    y = i << 8;
    if (y != 0) {
        n = n - 8;
        i = y;
    }
    y = i << 4;
    if (y != 0) {
        n = n - 4;
        i = y;
    }
    y = i << 2;
    if (y != 0) {
        n = n - 2;
        i = y;
    }
    return n - ((i << 1) >>> 31);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2606. 找到最大开销的子字符串](https://leetcode.cn/problems/find-the-substring-with-maximum-cost){#2606}

{{< tabs "2606" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        d = {c: v for c, v in zip(chars, vals)}
        ans = f = 0
        for c in s:
            v = d.get(c, ord(c) - ord('a') + 1)
            f = max(f, 0) + v
            ans = max(ans, f)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int[] d = new int[26];
        for (int i = 0; i < d.length; ++i) {
            d[i] = i + 1;
        }
        int m = chars.length();
        for (int i = 0; i < m; ++i) {
            d[chars.charAt(i) - 'a'] = vals[i];
        }
        int ans = 0, f = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int v = d[s.charAt(i) - 'a'];
            f = Math.max(f, 0) + v;
            ans = Math.max(ans, f);
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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> d(26);
        iota(d.begin(), d.end(), 1);
        int m = chars.size();
        for (int i = 0; i < m; ++i) {
            d[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, f = 0;
        for (char& c : s) {
            int v = d[c - 'a'];
            f = max(f, 0) + v;
            ans = max(ans, f);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumCostSubstring(s string, chars string, vals []int) (ans int) {
	d := [26]int{}
	for i := range d {
		d[i] = i + 1
	}
	for i, c := range chars {
		d[c-'a'] = vals[i]
	}
	f := 0
	for _, c := range s {
		v := d[c-'a']
		f = max(f, 0) + v
		ans = max(ans, f)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumCostSubstring(s: string, chars: string, vals: number[]): number {
    const d: number[] = Array.from({ length: 26 }, (_, i) => i + 1);
    for (let i = 0; i < chars.length; ++i) {
        d[chars.charCodeAt(i) - 97] = vals[i];
    }
    let ans = 0;
    let f = 0;
    for (const c of s) {
        f = Math.max(f, 0) + d[c.charCodeAt(0) - 97];
        ans = Math.max(ans, f);
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，一个字符&nbsp;<strong>互不相同</strong>&nbsp;的字符串&nbsp;<code>chars</code>&nbsp;和一个长度与 <code>chars</code>&nbsp;相同的整数数组&nbsp;<code>vals</code>&nbsp;。</p>

<p><strong>子字符串的开销</strong>&nbsp;是一个子字符串中所有字符对应价值之和。空字符串的开销是 <code>0</code>&nbsp;。</p>

<p><strong>字符的价值</strong>&nbsp;定义如下：</p>

<ul>
	<li>如果字符不在字符串&nbsp;<code>chars</code>&nbsp;中，那么它的价值是它在字母表中的位置（下标从 <strong>1</strong>&nbsp;开始）。

    <ul>
    	<li>比方说，<code>'a'</code>&nbsp;的价值为&nbsp;<code>1</code>&nbsp;，<code>'b'</code>&nbsp;的价值为&nbsp;<code>2</code>&nbsp;，以此类推，<code>'z'</code>&nbsp;的价值为&nbsp;<code>26</code>&nbsp;。</li>
    </ul>
    </li>
    <li>否则，如果这个字符在 <code>chars</code>&nbsp;中的位置为 <code>i</code>&nbsp;，那么它的价值就是&nbsp;<code>vals[i]</code>&nbsp;。</li>

</ul>

<p>请你返回字符串 <code>s</code>&nbsp;的所有子字符串中的最大开销。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "adaa", chars = "d", vals = [-1000]
<b>输出：</b>2
<b>解释：</b>字符 "a" 和 "d" 的价值分别为 1 和 -1000 。
最大开销子字符串是 "aa" ，它的开销为 1 + 1 = 2 。
2 是最大开销。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "abc", chars = "abc", vals = [-1,-1,-1]
<b>输出：</b>0
<b>解释：</b>字符 "a" ，"b" 和 "c" 的价值分别为 -1 ，-1 和 -1 。
最大开销子字符串是 "" ，它的开销为 0 。
0 是最大开销。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= chars.length &lt;= 26</code></li>
	<li><code>chars</code>&nbsp;只包含小写英文字母，且 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>vals.length == chars.length</code></li>
	<li><code>-1000 &lt;= vals[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 维护前缀和的最小值

我们根据题目描述，遍历字符串 $s$ 的每个字符 $c$，求出其对应的价值 $v$，然后更新当前的前缀和 $tot=tot+v$，那么以 $c$ 结尾的最大开销子字符串的开销为 $tot$ 减去前缀和的最小值 $mi$，即 $tot-mi$，我们更新答案 $ans=max(ans,tot-mi)$，并维护前缀和的最小值 $mi=min(mi,tot)$。

遍历结束后返回答案 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $s$ 的长度；而 $C$ 为字符集的大小，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        d = {c: v for c, v in zip(chars, vals)}
        ans = tot = mi = 0
        for c in s:
            v = d.get(c, ord(c) - ord('a') + 1)
            tot += v
            ans = max(ans, tot - mi)
            mi = min(mi, tot)
        return ans
```

#### Java

```java
class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int[] d = new int[26];
        for (int i = 0; i < d.length; ++i) {
            d[i] = i + 1;
        }
        int m = chars.length();
        for (int i = 0; i < m; ++i) {
            d[chars.charAt(i) - 'a'] = vals[i];
        }
        int ans = 0, tot = 0, mi = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int v = d[s.charAt(i) - 'a'];
            tot += v;
            ans = Math.max(ans, tot - mi);
            mi = Math.min(mi, tot);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> d(26);
        iota(d.begin(), d.end(), 1);
        int m = chars.size();
        for (int i = 0; i < m; ++i) {
            d[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, tot = 0, mi = 0;
        for (char& c : s) {
            int v = d[c - 'a'];
            tot += v;
            ans = max(ans, tot - mi);
            mi = min(mi, tot);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumCostSubstring(s string, chars string, vals []int) (ans int) {
	d := [26]int{}
	for i := range d {
		d[i] = i + 1
	}
	for i, c := range chars {
		d[c-'a'] = vals[i]
	}
	tot, mi := 0, 0
	for _, c := range s {
		v := d[c-'a']
		tot += v
		ans = max(ans, tot-mi)
		mi = min(mi, tot)
	}
	return
}
```

#### TypeScript

```ts
function maximumCostSubstring(s: string, chars: string, vals: number[]): number {
    const d: number[] = Array.from({ length: 26 }, (_, i) => i + 1);
    for (let i = 0; i < chars.length; ++i) {
        d[chars.charCodeAt(i) - 97] = vals[i];
    }
    let ans = 0;
    let tot = 0;
    let mi = 0;
    for (const c of s) {
        tot += d[c.charCodeAt(0) - 97];
        ans = Math.max(ans, tot - mi);
        mi = Math.min(mi, tot);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：转化为最大子数组和问题

我们可以将每个字符 $c$ 的价值 $v$ 看作是一个整数，那么题目实际上转化为求最大子数组和问题。

我们用变量 $f$ 维护以当前字符 $c$ 结尾的最大开销子字符串的开销，每次遍历到一个字符 $c$，更新 $f=max(f, 0) + v$，然后更新答案 $ans=max(ans,f)$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $s$ 的长度；而 $C$ 为字符集的大小，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        d = {c: v for c, v in zip(chars, vals)}
        ans = f = 0
        for c in s:
            v = d.get(c, ord(c) - ord('a') + 1)
            f = max(f, 0) + v
            ans = max(ans, f)
        return ans
```

#### Java

```java
class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int[] d = new int[26];
        for (int i = 0; i < d.length; ++i) {
            d[i] = i + 1;
        }
        int m = chars.length();
        for (int i = 0; i < m; ++i) {
            d[chars.charAt(i) - 'a'] = vals[i];
        }
        int ans = 0, f = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int v = d[s.charAt(i) - 'a'];
            f = Math.max(f, 0) + v;
            ans = Math.max(ans, f);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> d(26);
        iota(d.begin(), d.end(), 1);
        int m = chars.size();
        for (int i = 0; i < m; ++i) {
            d[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, f = 0;
        for (char& c : s) {
            int v = d[c - 'a'];
            f = max(f, 0) + v;
            ans = max(ans, f);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumCostSubstring(s string, chars string, vals []int) (ans int) {
	d := [26]int{}
	for i := range d {
		d[i] = i + 1
	}
	for i, c := range chars {
		d[c-'a'] = vals[i]
	}
	f := 0
	for _, c := range s {
		v := d[c-'a']
		f = max(f, 0) + v
		ans = max(ans, f)
	}
	return
}
```

#### TypeScript

```ts
function maximumCostSubstring(s: string, chars: string, vals: number[]): number {
    const d: number[] = Array.from({ length: 26 }, (_, i) => i + 1);
    for (let i = 0; i < chars.length; ++i) {
        d[chars.charCodeAt(i) - 97] = vals[i];
    }
    let ans = 0;
    let f = 0;
    for (const c of s) {
        f = Math.max(f, 0) + d[c.charCodeAt(0) - 97];
        ans = Math.max(ans, f);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2607. 使子数组元素和相等](https://leetcode.cn/problems/make-k-subarray-sums-equal){#2607}

{{< tabs "2607" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        g = gcd(n, k)
        ans = 0
        for i in range(g):
            t = sorted(arr[i:n:g])
            mid = t[len(t) >> 1]
            ans += sum(abs(x - mid) for x in t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long makeSubKSumEqual(int[] arr, int k) {
        int n = arr.length;
        int g = gcd(n, k);
        long ans = 0;
        for (int i = 0; i < g; ++i) {
            List<Integer> t = new ArrayList<>();
            for (int j = i; j < n; j += g) {
                t.add(arr[j]);
            }
            t.sort((a, b) -> a - b);
            int mid = t.get(t.size() >> 1);
            for (int x : t) {
                ans += Math.abs(x - mid);
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        long long ans = 0;
        for (int i = 0; i < g; ++i) {
            vector<int> t;
            for (int j = i; j < n; j += g) {
                t.push_back(arr[j]);
            }
            sort(t.begin(), t.end());
            int mid = t[t.size() / 2];
            for (int x : t) {
                ans += abs(x - mid);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeSubKSumEqual(arr []int, k int) (ans int64) {
	n := len(arr)
	g := gcd(n, k)
	for i := 0; i < g; i++ {
		t := []int{}
		for j := i; j < n; j += g {
			t = append(t, arr[j])
		}
		sort.Ints(t)
		mid := t[len(t)/2]
		for _, x := range t {
			ans += int64(abs(x - mid))
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

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeSubKSumEqual(arr: number[], k: number): number {
    const n = arr.length;
    const g = gcd(n, k);
    let ans = 0;
    for (let i = 0; i < g; ++i) {
        const t: number[] = [];
        for (let j = i; j < n; j += g) {
            t.push(arr[j]);
        }
        t.sort((a, b) => a - b);
        const mid = t[t.length >> 1];
        for (const x of t) {
            ans += Math.abs(x - mid);
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>arr</code> 和一个整数 <code>k</code> 。数组 <code>arr</code> 是一个循环数组。换句话说，数组中的最后一个元素的下一个元素是数组中的第一个元素，数组中第一个元素的前一个元素是数组中的最后一个元素。</p>

<p>你可以执行下述运算任意次：</p>

<ul>
	<li>选中 <code>arr</code> 中任意一个元素，并使其值加上 <code>1</code> 或减去 <code>1</code> 。</li>
</ul>

<p>执行运算使每个长度为 <code>k</code> 的 <strong>子数组</strong> 的元素总和都相等，返回所需要的最少运算次数。</p>

<p><strong>子数组</strong> 是数组的一个连续部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,4,1,3], k = 2
<strong>输出：</strong>1
<strong>解释：</strong>在下标为 1 的元素那里执行一次运算，使其等于 3 。
执行运算后，数组变为 [1,3,1,3] 。
- 0 处起始的子数组为 [1, 3] ，元素总和为 4 
- 1 处起始的子数组为 [3, 1] ，元素总和为 4 
- 2 处起始的子数组为 [1, 3] ，元素总和为 4 
- 3 处起始的子数组为 [3, 1] ，元素总和为 4 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [2,5,5,7], k = 3
<strong>输出：</strong>5
<strong>解释：</strong>在下标为 0 的元素那里执行三次运算，使其等于 5 。在下标为 3 的元素那里执行两次运算，使其等于 5 。
执行运算后，数组变为 [5,5,5,5] 。
- 0 处起始的子数组为 [5, 5, 5] ，元素总和为 15
- 1 处起始的子数组为 [5, 5, 5] ，元素总和为 15
- 2 处起始的子数组为 [5, 5, 5] ，元素总和为 15
- 3 处起始的子数组为 [5, 5, 5] ，元素总和为 15
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学（裴蜀定理） + 中位数贪心

题目要求每个长度为 $k$ 的子数组的元素总和相等，那么有以下等式成立：

$$
arr_i + arr_{i + 1} + \cdots + arr_{i + k - 1} = arr_{i + 1} + arr_{i + 2} + \cdots + arr_{i + k}
$$

化简得：

$$
arr_i = arr_{i + k}
$$

也即是说，数组 $arr$ 有一个大小为 $k$ 的循环节，而由于数组 $arr$ 是一个循环数组，那么数组 $arr$ 也有一个长度为 $n$ 的循环节。换句话说，数组 $arr$ 上间隔为 $k$，以及间隔为 $n$ 的元素均相等。即有：

$$
arr_i = arr_{i + k \times x + n \times y}
$$

根据裴蜀定理，有 $a \times x + b \times y = gcd(a, b)$，因此，有：

$$
arr_i = arr_{i + k \times x + n \times y} = arr_{i + gcd(k, n)}
$$

因此，数组 $arr$ 上的元素可以分为 $gcd(k, n)$ 组，每组的元素间隔为 $gcd(k, n)$，且每一组中的所有元素均相等。对于每一组，我们可以将其元素按照大小排序，然后取中位数，即可将该组中的所有元素变为中位数。对于所有组，我们将其中位数之差的绝对值求和，即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        g = gcd(n, k)
        ans = 0
        for i in range(g):
            t = sorted(arr[i:n:g])
            mid = t[len(t) >> 1]
            ans += sum(abs(x - mid) for x in t)
        return ans
```

#### Java

```java
class Solution {
    public long makeSubKSumEqual(int[] arr, int k) {
        int n = arr.length;
        int g = gcd(n, k);
        long ans = 0;
        for (int i = 0; i < g; ++i) {
            List<Integer> t = new ArrayList<>();
            for (int j = i; j < n; j += g) {
                t.add(arr[j]);
            }
            t.sort((a, b) -> a - b);
            int mid = t.get(t.size() >> 1);
            for (int x : t) {
                ans += Math.abs(x - mid);
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        long long ans = 0;
        for (int i = 0; i < g; ++i) {
            vector<int> t;
            for (int j = i; j < n; j += g) {
                t.push_back(arr[j]);
            }
            sort(t.begin(), t.end());
            int mid = t[t.size() / 2];
            for (int x : t) {
                ans += abs(x - mid);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func makeSubKSumEqual(arr []int, k int) (ans int64) {
	n := len(arr)
	g := gcd(n, k)
	for i := 0; i < g; i++ {
		t := []int{}
		for j := i; j < n; j += g {
			t = append(t, arr[j])
		}
		sort.Ints(t)
		mid := t[len(t)/2]
		for _, x := range t {
			ans += int64(abs(x - mid))
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

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function makeSubKSumEqual(arr: number[], k: number): number {
    const n = arr.length;
    const g = gcd(n, k);
    let ans = 0;
    for (let i = 0; i < g; ++i) {
        const t: number[] = [];
        for (let j = i; j < n; j += g) {
            t.push(arr[j]);
        }
        t.sort((a, b) => a - b);
        const mid = t[t.length >> 1];
        for (const x of t) {
            ans += Math.abs(x - mid);
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2608. 图中的最短环](https://leetcode.cn/problems/shortest-cycle-in-a-graph){#2608}

{{< tabs "2608" >}}

{{% tab "python" %}}
```python
class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        def bfs(u: int) -> int:
            dist = [-1] * n
            dist[u] = 0
            q = deque([(u, -1)])
            ans = inf
            while q:
                u, fa = q.popleft()
                for v in g[u]:
                    if dist[v] < 0:
                        dist[v] = dist[u] + 1
                        q.append((v, u))
                    elif v != fa:
                        ans = min(ans, dist[u] + dist[v] + 1)
            return ans

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        ans = min(bfs(i) for i in range(n))
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private final int inf = 1 << 30;

    public int findShortestCycle(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, bfs(i));
        }
        return ans < inf ? ans : -1;
    }

    private int bfs(int u) {
        int[] dist = new int[g.length];
        Arrays.fill(dist, -1);
        dist[u] = 0;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {u, -1});
        int ans = inf;
        while (!q.isEmpty()) {
            var p = q.poll();
            u = p[0];
            int fa = p[1];
            for (int v : g[u]) {
                if (dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    q.offer(new int[] {v, u});
                } else if (v != fa) {
                    ans = Math.min(ans, dist[u] + dist[v] + 1);
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
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        const int inf = 1 << 30;
        auto bfs = [&](int u) -> int {
            int dist[n];
            memset(dist, -1, sizeof(dist));
            dist[u] = 0;
            queue<pair<int, int>> q;
            q.emplace(u, -1);
            int ans = inf;
            while (!q.empty()) {
                auto p = q.front();
                u = p.first;
                int fa = p.second;
                q.pop();
                for (int v : g[u]) {
                    if (dist[v] < 0) {
                        dist[v] = dist[u] + 1;
                        q.emplace(v, u);
                    } else if (v != fa) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
            return ans;
        };
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, bfs(i));
        }
        return ans < inf ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findShortestCycle(n int, edges [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	const inf = 1 << 30
	bfs := func(u int) int {
		dist := make([]int, n)
		for i := range dist {
			dist[i] = -1
		}
		dist[u] = 0
		q := [][2]int{{u, -1}}
		ans := inf
		for len(q) > 0 {
			p := q[0]
			u = p[0]
			fa := p[1]
			q = q[1:]
			for _, v := range g[u] {
				if dist[v] < 0 {
					dist[v] = dist[u] + 1
					q = append(q, [2]int{v, u})
				} else if v != fa {
					ans = min(ans, dist[u]+dist[v]+1)
				}
			}
		}
		return ans
	}
	ans := inf
	for i := 0; i < n; i++ {
		ans = min(ans, bfs(i))
	}
	if ans < inf {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findShortestCycle(n: number, edges: number[][]): number {
    const g: number[][] = new Array(n).fill(0).map(() => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const inf = 1 << 30;
    let ans = inf;
    const bfs = (u: number) => {
        const dist: number[] = new Array(n).fill(-1);
        dist[u] = 0;
        const q: number[][] = [[u, -1]];
        let ans = inf;
        while (q.length) {
            const p = q.shift()!;
            u = p[0];
            const fa = p[1];
            for (const v of g[u]) {
                if (dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    q.push([v, u]);
                } else if (v !== fa) {
                    ans = Math.min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
        return ans;
    };
    for (let i = 0; i < n; ++i) {
        ans = Math.min(ans, bfs(i));
    }
    return ans < inf ? ans : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个含 <code>n</code> 个顶点的 <strong>双向</strong> 图，每个顶点按从 <code>0</code> 到 <code>n - 1</code> 标记。图中的边由二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示顶点 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。</p>

<p>返回图中 <strong>最短</strong> 环的长度。如果不存在环，则返回 <code>-1</code> 。</p>

<p><strong>环</strong> 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2608.Shortest%20Cycle%20in%20a%20Graph/images/cropped.png" style="width: 387px; height: 331px;">
<pre><strong>输入：</strong>n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
<strong>输出：</strong>3
<strong>解释：</strong>长度最小的循环是：0 -&gt; 1 -&gt; 2 -&gt; 0 
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2608.Shortest%20Cycle%20in%20a%20Graph/images/croppedagin.png" style="width: 307px; height: 307px;">
<pre><strong>输入：</strong>n = 4, edges = [[0,1],[0,2]]
<strong>输出：</strong>-1
<strong>解释：</strong>图中不存在循环
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= edges.length &lt;= 1000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>不存在重复的边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举删除的边 + BFS

我们先根据数组 $edges$ 构建出邻接表 $g$，其中 $g[u]$ 表示顶点 $u$ 的所有邻接点。

接下来，我们枚举双向边 $(u, v)$，如果删除该边后，从顶点 $u$ 到顶点 $v$ 的路径依然存在，则包含该边的最短环的长度为 $dist[v] + 1$，其中 $dist[v]$ 表示从顶点 $u$ 到顶点 $v$ 的最短路径长度。我们取所有这样的环的最小值即可。

时间复杂度 $O(m^2)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为数组 $edges$ 的长度以及顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        def bfs(u: int, v: int) -> int:
            dist = [inf] * n
            dist[u] = 0
            q = deque([u])
            while q:
                i = q.popleft()
                for j in g[i]:
                    if (i, j) != (u, v) and (j, i) != (u, v) and dist[j] == inf:
                        dist[j] = dist[i] + 1
                        q.append(j)
            return dist[v] + 1

        g = defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)
        ans = min(bfs(u, v) for u, v in edges)
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private final int inf = 1 << 30;

    public int findShortestCycle(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        int ans = inf;
        for (var e : edges) {
            int u = e[0], v = e[1];
            ans = Math.min(ans, bfs(u, v));
        }
        return ans < inf ? ans : -1;
    }

    private int bfs(int u, int v) {
        int[] dist = new int[g.length];
        Arrays.fill(dist, inf);
        dist[u] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(u);
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                if ((i == u && j == v) || (i == v && j == u) || dist[j] != inf) {
                    continue;
                }
                dist[j] = dist[i] + 1;
                q.offer(j);
            }
        }
        return dist[v] + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        const int inf = 1 << 30;
        auto bfs = [&](int u, int v) -> int {
            int dist[n];
            fill(dist, dist + n, inf);
            dist[u] = 0;
            queue<int> q{{u}};
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if ((i == u && j == v) || (i == v && j == u) || dist[j] != inf) {
                        continue;
                    }
                    dist[j] = dist[i] + 1;
                    q.push(j);
                }
            }
            return dist[v] + 1;
        };
        int ans = inf;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            ans = min(ans, bfs(u, v));
        }
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
func findShortestCycle(n int, edges [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	const inf = 1 << 30
	bfs := func(u, v int) int {
		dist := make([]int, n)
		for i := range dist {
			dist[i] = inf
		}
		dist[u] = 0
		q := []int{u}
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			for _, j := range g[i] {
				if (i == u && j == v) || (i == v && j == u) || dist[j] != inf {
					continue
				}
				dist[j] = dist[i] + 1
				q = append(q, j)
			}
		}
		return dist[v] + 1
	}
	ans := inf
	for _, e := range edges {
		u, v := e[0], e[1]
		ans = min(ans, bfs(u, v))
	}
	if ans < inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function findShortestCycle(n: number, edges: number[][]): number {
    const g: number[][] = new Array(n).fill(0).map(() => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const inf = 1 << 30;
    let ans = inf;
    const bfs = (u: number, v: number) => {
        const dist: number[] = new Array(n).fill(inf);
        dist[u] = 0;
        const q: number[] = [u];
        while (q.length) {
            const i = q.shift()!;
            for (const j of g[i]) {
                if ((i == u && j == v) || (i == v && j == u) || dist[j] != inf) {
                    continue;
                }
                dist[j] = dist[i] + 1;
                q.push(j);
            }
        }
        return 1 + dist[v];
    };
    for (const [u, v] of edges) {
        ans = Math.min(ans, bfs(u, v));
    }
    return ans < inf ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举点 + BFS

与方法一类似，我们先根据数组 $edges$ 构建出邻接表 $g$，其中 $g[u]$ 表示顶点 $u$ 的所有邻接点。

接下来，我们枚举顶点 $u$，如果从顶点 $u$ 出发，有两条路径都到达了顶点 $v$，说明当前找到了一个环，长度为两条路径的长度之和。我们取所有这样的环的最小值即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为数组 $edges$ 的长度以及顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        def bfs(u: int) -> int:
            dist = [-1] * n
            dist[u] = 0
            q = deque([(u, -1)])
            ans = inf
            while q:
                u, fa = q.popleft()
                for v in g[u]:
                    if dist[v] < 0:
                        dist[v] = dist[u] + 1
                        q.append((v, u))
                    elif v != fa:
                        ans = min(ans, dist[u] + dist[v] + 1)
            return ans

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        ans = min(bfs(i) for i in range(n))
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private final int inf = 1 << 30;

    public int findShortestCycle(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, bfs(i));
        }
        return ans < inf ? ans : -1;
    }

    private int bfs(int u) {
        int[] dist = new int[g.length];
        Arrays.fill(dist, -1);
        dist[u] = 0;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {u, -1});
        int ans = inf;
        while (!q.isEmpty()) {
            var p = q.poll();
            u = p[0];
            int fa = p[1];
            for (int v : g[u]) {
                if (dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    q.offer(new int[] {v, u});
                } else if (v != fa) {
                    ans = Math.min(ans, dist[u] + dist[v] + 1);
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
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        const int inf = 1 << 30;
        auto bfs = [&](int u) -> int {
            int dist[n];
            memset(dist, -1, sizeof(dist));
            dist[u] = 0;
            queue<pair<int, int>> q;
            q.emplace(u, -1);
            int ans = inf;
            while (!q.empty()) {
                auto p = q.front();
                u = p.first;
                int fa = p.second;
                q.pop();
                for (int v : g[u]) {
                    if (dist[v] < 0) {
                        dist[v] = dist[u] + 1;
                        q.emplace(v, u);
                    } else if (v != fa) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
            return ans;
        };
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, bfs(i));
        }
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
func findShortestCycle(n int, edges [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	const inf = 1 << 30
	bfs := func(u int) int {
		dist := make([]int, n)
		for i := range dist {
			dist[i] = -1
		}
		dist[u] = 0
		q := [][2]int{{u, -1}}
		ans := inf
		for len(q) > 0 {
			p := q[0]
			u = p[0]
			fa := p[1]
			q = q[1:]
			for _, v := range g[u] {
				if dist[v] < 0 {
					dist[v] = dist[u] + 1
					q = append(q, [2]int{v, u})
				} else if v != fa {
					ans = min(ans, dist[u]+dist[v]+1)
				}
			}
		}
		return ans
	}
	ans := inf
	for i := 0; i < n; i++ {
		ans = min(ans, bfs(i))
	}
	if ans < inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function findShortestCycle(n: number, edges: number[][]): number {
    const g: number[][] = new Array(n).fill(0).map(() => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const inf = 1 << 30;
    let ans = inf;
    const bfs = (u: number) => {
        const dist: number[] = new Array(n).fill(-1);
        dist[u] = 0;
        const q: number[][] = [[u, -1]];
        let ans = inf;
        while (q.length) {
            const p = q.shift()!;
            u = p[0];
            const fa = p[1];
            for (const v of g[u]) {
                if (dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    q.push([v, u]);
                } else if (v !== fa) {
                    ans = Math.min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
        return ans;
    };
    for (let i = 0; i < n; ++i) {
        ans = Math.min(ans, bfs(i));
    }
    return ans < inf ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2609. 最长平衡子字符串](https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string){#2609}

{{< tabs "2609" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = zero = one = 0
        for c in s:
            if c == '0':
                if one:
                    zero = one = 0
                zero += 1
            else:
                one += 1
                ans = max(ans, 2 * min(one, zero))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int zero = 0, one = 0;
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = Math.max(ans, 2 * Math.min(zero, ++one));
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
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0, one = 0;
        int ans = 0;
        for (char& c : s) {
            if (c == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = max(ans, 2 * min(zero, ++one));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheLongestBalancedSubstring(s string) (ans int) {
	zero, one := 0, 0
	for _, c := range s {
		if c == '0' {
			if one > 0 {
				zero, one = 0, 0
			}
			zero++
		} else {
			one++
			ans = max(ans, 2*min(zero, one))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheLongestBalancedSubstring(s: string): number {
    let zero = 0;
    let one = 0;
    let ans = 0;
    for (const c of s) {
        if (c === '0') {
            if (one > 0) {
                zero = 0;
                one = 0;
            }
            ++zero;
        } else {
            ans = Math.max(ans, 2 * Math.min(zero, ++one));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let mut zero = 0;
        let mut one = 0;
        let mut ans = 0;

        for &c in s.as_bytes().iter() {
            if c == b'0' {
                if one > 0 {
                    zero = 0;
                    one = 0;
                }
                zero += 1;
            } else {
                one += 1;
                ans = std::cmp::max(ans, std::cmp::min(zero, one) * 2);
            }
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

<p>给你一个仅由 <code>0</code> 和 <code>1</code> 组成的二进制字符串 <code>s</code> 。<span style="">&nbsp;</span><span style="">&nbsp;</span></p>

<p>如果子字符串中 <strong>所有的<span style=""> </span></strong><code><span style="">0</span></code><strong><span style=""> </span>都在 </strong><code>1</code><strong> 之前</strong> 且其中 <code>0</code> 的数量等于 <code>1</code> 的数量，则认为 <code>s</code> 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。<span style="">&nbsp;</span></p>

<p>返回&nbsp;<span style=""> </span><code>s</code> 中最长的平衡子字符串长度。</p>

<p>子字符串是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "01000111"
<strong>输出：</strong>6
<strong>解释：</strong>最长的平衡子字符串是 "000111" ，长度为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "00111"
<strong>输出：</strong>4
<strong>解释：</strong>最长的平衡子字符串是 "0011" ，长度为 <span style="">&nbsp;</span>4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "111"
<strong>输出：</strong>0
<strong>解释：</strong>除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

注意到数据范围很小，因此，我们可以枚举所有的子串 $s[i..j]$，检查其是否为平衡子串，如果是，则更新答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        def check(i, j):
            cnt = 0
            for k in range(i, j + 1):
                if s[k] == '1':
                    cnt += 1
                elif cnt:
                    return False
            return cnt * 2 == (j - i + 1)

        n = len(s)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                if check(i, j):
                    ans = max(ans, j - i + 1)
        return ans
```

#### Java

```java
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(s, i, j)) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    private boolean check(String s, int i, int j) {
        int cnt = 0;
        for (int k = i; k <= j; ++k) {
            if (s.charAt(k) == '1') {
                ++cnt;
            } else if (cnt > 0) {
                return false;
            }
        }
        return cnt * 2 == j - i + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        auto check = [&](int i, int j) -> bool {
            int cnt = 0;
            for (int k = i; k <= j; ++k) {
                if (s[k] == '1') {
                    ++cnt;
                } else if (cnt) {
                    return false;
                }
            }
            return cnt * 2 == j - i + 1;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findTheLongestBalancedSubstring(s string) (ans int) {
	n := len(s)
	check := func(i, j int) bool {
		cnt := 0
		for k := i; k <= j; k++ {
			if s[k] == '1' {
				cnt++
			} else if cnt > 0 {
				return false
			}
		}
		return cnt*2 == j-i+1
	}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if check(i, j) {
				ans = max(ans, j-i+1)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findTheLongestBalancedSubstring(s: string): number {
    const n = s.length;
    let ans = 0;
    const check = (i: number, j: number): boolean => {
        let cnt = 0;
        for (let k = i; k <= j; ++k) {
            if (s[k] === '1') {
                ++cnt;
            } else if (cnt > 0) {
                return false;
            }
        }
        return cnt * 2 === j - i + 1;
    };
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; j += 2) {
            if (check(i, j)) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let check = |i: usize, j: usize| -> bool {
            let mut cnt = 0;

            for k in i..=j {
                if s.as_bytes()[k] == b'1' {
                    cnt += 1;
                } else if cnt > 0 {
                    return false;
                }
            }

            cnt * 2 == j - i + 1
        };

        let mut ans = 0;
        let n = s.len();
        for i in 0..n - 1 {
            for j in (i + 1..n).rev() {
                if j - i + 1 < ans {
                    break;
                }

                if check(i, j) {
                    ans = std::cmp::max(ans, j - i + 1);
                    break;
                }
            }
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

我们用变量 $zero$ 和 $one$ 分别记录当前连续的 $0$ 和 $1$ 的个数。

遍历字符串 $s$，对于当前字符 $c$：

-   如果当前字符为 `'0'`，我们判断此时 $one$ 是否大于 $0$，是则将 $zero$ 和 $one$ 重置为 $0$，接下来将 $zero$ 加 $1$。
-   如果当前字符为 `'1'`，则将 $one$ 加 $1$，并更新答案为 $ans = \max(ans, 2 \times \min(one, zero))$。

遍历结束后，即可得到最长的平衡子串的长度。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = zero = one = 0
        for c in s:
            if c == '0':
                if one:
                    zero = one = 0
                zero += 1
            else:
                one += 1
                ans = max(ans, 2 * min(one, zero))
        return ans
```

#### Java

```java
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int zero = 0, one = 0;
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = Math.max(ans, 2 * Math.min(zero, ++one));
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
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0, one = 0;
        int ans = 0;
        for (char& c : s) {
            if (c == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = max(ans, 2 * min(zero, ++one));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findTheLongestBalancedSubstring(s string) (ans int) {
	zero, one := 0, 0
	for _, c := range s {
		if c == '0' {
			if one > 0 {
				zero, one = 0, 0
			}
			zero++
		} else {
			one++
			ans = max(ans, 2*min(zero, one))
		}
	}
	return
}
```

#### TypeScript

```ts
function findTheLongestBalancedSubstring(s: string): number {
    let zero = 0;
    let one = 0;
    let ans = 0;
    for (const c of s) {
        if (c === '0') {
            if (one > 0) {
                zero = 0;
                one = 0;
            }
            ++zero;
        } else {
            ans = Math.max(ans, 2 * Math.min(zero, ++one));
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let mut zero = 0;
        let mut one = 0;
        let mut ans = 0;

        for &c in s.as_bytes().iter() {
            if c == b'0' {
                if one > 0 {
                    zero = 0;
                    one = 0;
                }
                zero += 1;
            } else {
                one += 1;
                ans = std::cmp::max(ans, std::cmp::min(zero, one) * 2);
            }
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
