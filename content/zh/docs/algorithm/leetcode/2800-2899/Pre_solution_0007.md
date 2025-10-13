---
title: "2860_让所有学生保持开心的分组方法数"
date: 2025-10-08T18:39:37+08:00
weight: 7
tags: [二分查找, 位运算, 动态规划, 单调栈, 博弈, 双指针, 哈希表, 字符串, 排序, 数学, 数组, 数论, 枚举, 栈, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [2860_让所有学生保持开心的分组方法数](#2860)
#### [数组](#2860)
#### [枚举](#2860)
#### [排序](#2860)
### [2861_最大合金数](#2861)
#### [数组](#2861)
#### [二分查找](#2861)
### [2862_完全子集的最大元素和](#2862)
#### [数组](#2862)
#### [数学](#2862)
#### [数论](#2862)
### [2863_最长半递减子数组的长度 🔒](#2863)
#### [栈](#2863)
#### [数组](#2863)
#### [排序](#2863)
#### [单调栈](#2863)
### [2864_最大二进制奇数](#2864)
#### [贪心](#2864)
#### [数学](#2864)
#### [字符串](#2864)
### [2865_美丽塔 I](#2865)
#### [栈](#2865)
#### [数组](#2865)
#### [单调栈](#2865)
### [2866_美丽塔 II](#2866)
#### [栈](#2866)
#### [数组](#2866)
#### [单调栈](#2866)
### [2867_统计树中的合法路径数目](#2867)
#### [树](#2867)
#### [深度优先搜索](#2867)
#### [数学](#2867)
#### [动态规划](#2867)
#### [数论](#2867)
### [2868_单词游戏 🔒](#2868)
#### [贪心](#2868)
#### [数组](#2868)
#### [数学](#2868)
#### [双指针](#2868)
#### [字符串](#2868)
#### [博弈](#2868)
### [2869_收集元素的最少操作次数](#2869)
#### [位运算](#2869)
#### [数组](#2869)
#### [哈希表](#2869)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2860_让所有学生保持开心的分组方法数
___
#### 数组
___
#### 枚举
___
#### 排序
---
### 2861_最大合金数
___
#### 数组
___
#### 二分查找
---
### 2862_完全子集的最大元素和
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2863_最长半递减子数组的长度 🔒
___
#### 栈
___
#### 数组
___
#### 排序
___
#### 单调栈
---
### 2864_最大二进制奇数
___
#### 贪心
___
#### 数学
___
#### 字符串
---
### 2865_美丽塔 I
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 2866_美丽塔 II
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 2867_统计树中的合法路径数目
___
#### 树
___
#### 深度优先搜索
___
#### 数学
___
#### 动态规划
___
#### 数论
---
### 2868_单词游戏 🔒
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 双指针
___
#### 字符串
___
#### 博弈
---
### 2869_收集元素的最少操作次数
___
#### 位运算
___
#### 数组
___
#### 哈希表
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 博弈 | 双指针 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 栈 | 树 |
| 深度优先搜索 | 贪心 |  |

# [2860. 让所有学生保持开心的分组方法数](https://leetcode.cn/problems/happy-students){#2860}

{{< tabs "2860" >}}

{{% tab "python" %}}
```python
class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        for i in range(n + 1):
            if i and nums[i - 1] >= i:
                continue
            if i < n and nums[i] <= i:
                continue
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if ((i == 0 || nums.get(i - 1) < i) && (i == n || nums.get(i) > i)) {
                ans++;
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
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if ((i && nums[i - 1] >= i) || (i < n && nums[i] <= i)) {
                continue;
            }
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countWays(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i <= n; i++ {
		if (i > 0 && nums[i-1] >= i) || (i < n && nums[i] <= i) {
			continue
		}
		ans++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countWays(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i <= n; ++i) {
        if ((i && nums[i - 1] >= i) || (i < n && nums[i] <= i)) {
            continue;
        }
        ++ans;
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

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> ，其中 <code>n</code> 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：</p>

<p>如果能够满足下述两个条件之一，则认为第 <code>i</code> 位学生将会保持开心：</p>

<ul>
	<li>这位学生被选中，并且被选中的学生人数 <strong>严格大于</strong> <code>nums[i]</code> 。</li>
	<li>这位学生没有被选中，并且被选中的学生人数 <strong>严格小于</strong> <code>nums[i]</code> 。</li>
</ul>

<p>返回能够满足让所有学生保持开心的分组方法的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>2
<strong>解释：</strong>
有两种可行的方法：
班主任没有选中学生。
班主任选中所有学生形成一组。 
如果班主任仅选中一个学生来完成分组，那么两个学生都无法保持开心。因此，仅存在两种可行的方法。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,0,3,3,6,7,2,7]
<strong>输出：</strong>3
<strong>解释：</strong>
存在三种可行的方法：
班主任选中下标为 1 的学生形成一组。
班主任选中下标为 1、2、3、6 的学生形成一组。
班主任选中所有学生形成一组。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

假设选出了 $k$ 个学生，那么以下情况成立：

-   如果 $nums[i] = k$，那么不存在分组方法；
-   如果 $nums[i] \gt k$，那么学生 $i$ 不被选中；
-   如果 $nums[i] \lt k$，那么学生 $i$ 被选中。

因此，被选中的学生一定是排序后的 $nums$ 数组中的前 $k$ 个元素。

我们在 $[0,..n]$ 范围内枚举 $k$，对于当前选出的学生人数 $i$，我们可以得到组内最大的学生编号 $i-1$，数字为 $nums[i-1]$。如果 $i \gt 0$ 并且 $nums[i-1] \ge i$，那么不存在分组方法；如果 $i \lt n$ 并且 $nums[i] \le i$，那么不存在分组方法。否则，存在分组方法，答案加一。

枚举结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        for i in range(n + 1):
            if i and nums[i - 1] >= i:
                continue
            if i < n and nums[i] <= i:
                continue
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if ((i == 0 || nums.get(i - 1) < i) && (i == n || nums.get(i) > i)) {
                ans++;
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
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if ((i && nums[i - 1] >= i) || (i < n && nums[i] <= i)) {
                continue;
            }
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func countWays(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i <= n; i++ {
		if (i > 0 && nums[i-1] >= i) || (i < n && nums[i] <= i) {
			continue
		}
		ans++
	}
	return
}
```

#### TypeScript

```ts
function countWays(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i <= n; ++i) {
        if ((i && nums[i - 1] >= i) || (i < n && nums[i] <= i)) {
            continue;
        }
        ++ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2861. 最大合金数](https://leetcode.cn/problems/maximum-number-of-alloys){#2861}

{{< tabs "2861" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumberOfAlloys(
        self,
        n: int,
        k: int,
        budget: int,
        composition: List[List[int]],
        stock: List[int],
        cost: List[int],
    ) -> int:
        ans = 0
        for c in composition:
            l, r = 0, budget + stock[0]
            while l < r:
                mid = (l + r + 1) >> 1
                s = sum(max(0, mid * x - y) * z for x, y, z in zip(c, stock, cost))
                if s <= budget:
                    l = mid
                else:
                    r = mid - 1
            ans = max(ans, l)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    int n;
    int budget;
    List<List<Integer>> composition;
    List<Integer> stock;
    List<Integer> cost;

    boolean isValid(long target) {
        for (List<Integer> currMachine : composition) {
            long remain = budget;
            for (int j = 0; j < n && remain >= 0; j++) {
                long need = Math.max(0, currMachine.get(j) * target - stock.get(j));
                remain -= need * cost.get(j);
            }
            if (remain >= 0) {
                return true;
            }
        }
        return false;
    }

    public int maxNumberOfAlloys(int n, int k, int budget, List<List<Integer>> composition,
        List<Integer> stock, List<Integer> cost) {
        this.n = n;
        this.budget = budget;
        this.composition = composition;
        this.stock = stock;
        this.cost = cost;
        int l = -1;
        int r = budget / cost.get(0) + stock.get(0);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (isValid(mid)) {
                l = mid;
            } else {
                r = mid - 1;
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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        auto isValid = [&](long long target) {
            for (int i = 0; i < k; i++) {
                long long remain = budget;
                auto currMachine = composition[i];
                for (int j = 0; j < n && remain >= 0; j++) {
                    long long need = max(0LL, target * currMachine[j] - stock[j]);
                    remain -= need * cost[j];
                }
                if (remain >= 0) {
                    return true;
                }
            }
            return false;
        };
        long long l = 0, r = budget + stock[0];
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (isValid(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumberOfAlloys(n int, k int, budget int, composition [][]int, stock []int, cost []int) int {
	isValid := func(target int) bool {
		for _, currMachine := range composition {
			remain := budget
			for i, x := range currMachine {
				need := max(0, x*target-stock[i])
				remain -= need * cost[i]
			}
			if remain >= 0 {
				return true
			}
		}
		return false
	}

	l, r := 0, budget+stock[0]
	for l < r {
		mid := (l + r + 1) >> 1
		if isValid(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumberOfAlloys(
    n: number,
    k: number,
    budget: number,
    composition: number[][],
    stock: number[],
    cost: number[],
): number {
    let l = 0;
    let r = budget + stock[0];
    const isValid = (target: number): boolean => {
        for (const currMachine of composition) {
            let remain = budget;
            for (let i = 0; i < n; ++i) {
                let need = Math.max(0, target * currMachine[i] - stock[i]);
                remain -= need * cost[i];
            }
            if (remain >= 0) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (isValid(mid)) {
            l = mid;
        } else {
            r = mid - 1;
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

<p>假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。现在共有 <code>n</code> 种不同类型的金属可以使用，并且你可以使用 <code>k</code> 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。</p>

<p>对于第 <code>i</code> 台机器而言，创建合金需要 <code>composition[i][j]</code> 份 <code>j</code> 类型金属。最初，你拥有 <code>stock[x]</code> 份 <code>x</code> 类型金属，而每购入一份 <code>x</code> 类型金属需要花费 <code>cost[x]</code> 的金钱。</p>

<p>给你整数 <code>n</code>、<code>k</code>、<code>budget</code>，下标从 <strong>1</strong> 开始的二维数组 <code>composition</code>，两个下标从 <strong>1</strong> 开始的数组 <code>stock</code> 和 <code>cost</code>，请你在预算不超过 <code>budget</code> 金钱的前提下，<strong>最大化</strong> 公司制造合金的数量。</p>

<p><strong>所有合金都需要由同一台机器制造。</strong></p>

<p>返回公司可以制造的最大合金数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,0], cost = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>最优的方法是使用第 1 台机器来制造合金。
要想制造 2 份合金，我们需要购买：
- 2 份第 1 类金属。
- 2 份第 2 类金属。
- 2 份第 3 类金属。
总共需要 2 * 1 + 2 * 2 + 2 * 3 = 12 的金钱，小于等于预算 15 。
注意，我们最开始时候没有任何一类金属，所以必须买齐所有需要的金属。
可以证明在示例条件下最多可以制造 2 份合金。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,100], cost = [1,2,3]
<strong>输出：</strong>5
<strong>解释：</strong>最优的方法是使用第 2 台机器来制造合金。 
要想制造 5 份合金，我们需要购买： 
- 5 份第 1 类金属。
- 5 份第 2 类金属。 
- 0 份第 3 类金属。 
总共需要 5 * 1 + 5 * 2 + 0 * 3 = 15 的金钱，小于等于预算 15 。 
可以证明在示例条件下最多可以制造 5 份合金。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 3, budget = 10, composition = [[2,1],[1,2],[1,1]], stock = [1,1], cost = [5,5]
<strong>输出：</strong>2
<strong>解释：</strong>最优的方法是使用第 3 台机器来制造合金。
要想制造 2 份合金，我们需要购买：
- 1 份第 1 类金属。
- 1 份第 2 类金属。
总共需要 1 * 5 + 1 * 5 = 10 的金钱，小于等于预算 10 。
可以证明在示例条件下最多可以制造 2 份合金。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 100</code></li>
	<li><code>0 &lt;= budget &lt;= 10<sup>8</sup></code></li>
	<li><code>composition.length == k</code></li>
	<li><code>composition[i].length == n</code></li>
	<li><code>1 &lt;= composition[i][j] &lt;= 100</code></li>
	<li><code>stock.length == cost.length == n</code></li>
	<li><code>0 &lt;= stock[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= cost[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，所有合金都需要由同一台机器制造，因此我们可以枚举使用哪一台机器来制造合金。

对于每一台机器，我们可以使用二分查找的方法找出最大的整数 $x$，使得我们可以使用这台机器制造 $x$ 份合金。找出所有 $x$ 中的最大值即为答案。

时间复杂度 $O(n \times k \times \log M)$，其中 $M$ 是二分查找的上界，本题中 $M \leq 2 \times 10^8$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumberOfAlloys(
        self,
        n: int,
        k: int,
        budget: int,
        composition: List[List[int]],
        stock: List[int],
        cost: List[int],
    ) -> int:
        ans = 0
        for c in composition:
            l, r = 0, budget + stock[0]
            while l < r:
                mid = (l + r + 1) >> 1
                s = sum(max(0, mid * x - y) * z for x, y, z in zip(c, stock, cost))
                if s <= budget:
                    l = mid
                else:
                    r = mid - 1
            ans = max(ans, l)
        return ans
```

#### Java

```java
class Solution {
    int n;
    int budget;
    List<List<Integer>> composition;
    List<Integer> stock;
    List<Integer> cost;

    boolean isValid(long target) {
        for (List<Integer> currMachine : composition) {
            long remain = budget;
            for (int j = 0; j < n && remain >= 0; j++) {
                long need = Math.max(0, currMachine.get(j) * target - stock.get(j));
                remain -= need * cost.get(j);
            }
            if (remain >= 0) {
                return true;
            }
        }
        return false;
    }

    public int maxNumberOfAlloys(int n, int k, int budget, List<List<Integer>> composition,
        List<Integer> stock, List<Integer> cost) {
        this.n = n;
        this.budget = budget;
        this.composition = composition;
        this.stock = stock;
        this.cost = cost;
        int l = -1;
        int r = budget / cost.get(0) + stock.get(0);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (isValid(mid)) {
                l = mid;
            } else {
                r = mid - 1;
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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        auto isValid = [&](long long target) {
            for (int i = 0; i < k; i++) {
                long long remain = budget;
                auto currMachine = composition[i];
                for (int j = 0; j < n && remain >= 0; j++) {
                    long long need = max(0LL, target * currMachine[j] - stock[j]);
                    remain -= need * cost[j];
                }
                if (remain >= 0) {
                    return true;
                }
            }
            return false;
        };
        long long l = 0, r = budget + stock[0];
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (isValid(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maxNumberOfAlloys(n int, k int, budget int, composition [][]int, stock []int, cost []int) int {
	isValid := func(target int) bool {
		for _, currMachine := range composition {
			remain := budget
			for i, x := range currMachine {
				need := max(0, x*target-stock[i])
				remain -= need * cost[i]
			}
			if remain >= 0 {
				return true
			}
		}
		return false
	}

	l, r := 0, budget+stock[0]
	for l < r {
		mid := (l + r + 1) >> 1
		if isValid(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maxNumberOfAlloys(
    n: number,
    k: number,
    budget: number,
    composition: number[][],
    stock: number[],
    cost: number[],
): number {
    let l = 0;
    let r = budget + stock[0];
    const isValid = (target: number): boolean => {
        for (const currMachine of composition) {
            let remain = budget;
            for (let i = 0; i < n; ++i) {
                let need = Math.max(0, target * currMachine[i] - stock[i]);
                remain -= need * cost[i];
            }
            if (remain >= 0) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (isValid(mid)) {
            l = mid;
        } else {
            r = mid - 1;
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

# [2862. 完全子集的最大元素和](https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices){#2862}

{{< tabs "2862" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for k in range(1, n + 1):
            t = 0
            j = 1
            while k * j * j <= n:
                t += nums[k * j * j - 1]
                j += 1
            ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSum(List<Integer> nums) {
        long ans = 0;
        int n = nums.size();
        boolean[] used = new boolean[n + 1];
        int bound = (int) Math.floor(Math.sqrt(n));
        int[] squares = new int[bound + 1];
        for (int i = 1; i <= bound + 1; i++) {
            squares[i - 1] = i * i;
        }
        for (int i = 1; i <= n; i++) {
            long res = 0;
            int idx = 0;
            int curr = i * squares[idx];
            while (curr <= n) {
                res += nums.get(curr - 1);
                curr = i * squares[++idx];
            }
            ans = Math.max(ans, res);
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
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int k = 1; k <= n; ++k) {
            long long t = 0;
            for (int j = 1; k * j * j <= n; ++j) {
                t += nums[k * j * j - 1];
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSum(nums []int) (ans int64) {
	n := len(nums)
	for k := 1; k <= n; k++ {
		var t int64
		for j := 1; k*j*j <= n; j++ {
			t += int64(nums[k*j*j-1])
		}
		ans = max(ans, t)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSum(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    for (let k = 1; k <= n; ++k) {
        let t = 0;
        for (let j = 1; k * j * j <= n; ++j) {
            t += nums[k * j * j - 1];
        }
        ans = Math.max(ans, t);
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

<p>给你一个下标从 <strong>1</strong> 开始、由 <code>n</code> 个整数组成的数组。你需要从&nbsp;<code>nums</code>&nbsp;选择一个&nbsp;<strong>完全集</strong>，其中每对元素下标的乘积都是一个 <span data-keyword="perfect-square">完全平方数</span>，例如选择&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>a<sub>j</sub></code>&nbsp;，<code>i * j</code>&nbsp;一定是完全平方数。</p>

<p>返回&nbsp;<strong>完全子集</strong> 所能取到的 <strong>最大元素和</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [8,7,3,5,7,2,4,9]</span></p>

<p><strong>输出：</strong><span class="example-io">16</span></p>

<p><strong>解释：</strong></p>

<p>我们选择下标为 2 和 8 的元素，并且&nbsp;<code>2 * 8</code>&nbsp;是一个完全平方数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [8,10,3,8,1,13,7,9,4]</span></p>

<p><span class="example-io"><b>输出：</b>20</span></p>

<p><strong>解释：</strong></p>

<p>我们选择下标为 1, 4, 9 的元素。<code>1 * 4</code>, <code>1 * 9</code>, <code>4 * 9</code>&nbsp;是完全平方数。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们注意到，如果一个数字可以表示成 $k \times j^2$ 的形式，那么所有该形式的数字的 $k$ 是相同的。

因此，我们可以在 $[1,..n]$ 范围内枚举 $k$，然后从 $1$ 开始枚举 $j$，每一次累加 $nums[k \times j^2 - 1]$ 的值到 $t$ 中，直到 $k \times j^2 > n$。此时更新答案为 $ans = \max(ans, t)$。

最后返回答案 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for k in range(1, n + 1):
            t = 0
            j = 1
            while k * j * j <= n:
                t += nums[k * j * j - 1]
                j += 1
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public long maximumSum(List<Integer> nums) {
        long ans = 0;
        int n = nums.size();
        for (int k = 1; k <= n; ++k) {
            long t = 0;
            for (int j = 1; k * j * j <= n; ++j) {
                t += nums.get(k * j * j - 1);
            }
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### Java

```java
class Solution {
    public long maximumSum(List<Integer> nums) {
        long ans = 0;
        int n = nums.size();
        boolean[] used = new boolean[n + 1];
        int bound = (int) Math.floor(Math.sqrt(n));
        int[] squares = new int[bound + 1];
        for (int i = 1; i <= bound + 1; i++) {
            squares[i - 1] = i * i;
        }
        for (int i = 1; i <= n; i++) {
            long res = 0;
            int idx = 0;
            int curr = i * squares[idx];
            while (curr <= n) {
                res += nums.get(curr - 1);
                curr = i * squares[++idx];
            }
            ans = Math.max(ans, res);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int k = 1; k <= n; ++k) {
            long long t = 0;
            for (int j = 1; k * j * j <= n; ++j) {
                t += nums[k * j * j - 1];
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSum(nums []int) (ans int64) {
	n := len(nums)
	for k := 1; k <= n; k++ {
		var t int64
		for j := 1; k*j*j <= n; j++ {
			t += int64(nums[k*j*j-1])
		}
		ans = max(ans, t)
	}
	return
}
```

#### TypeScript

```ts
function maximumSum(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    for (let k = 1; k <= n; ++k) {
        let t = 0;
        for (let j = 1; k * j * j <= n; ++j) {
            t += nums[k * j * j - 1];
        }
        ans = Math.max(ans, t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2863. 最长半递减子数组的长度 🔒](https://leetcode.cn/problems/maximum-length-of-semi-decreasing-subarrays){#2863}

{{< tabs "2863" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubarrayLength(self, nums: List[int]) -> int:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans, k = 0, inf
        for x in sorted(d, reverse=True):
            ans = max(ans, d[x][-1] - k + 1)
            k = min(k, d[x][0])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubarrayLength(int[] nums) {
        TreeMap<Integer, List<Integer>> d = new TreeMap<>(Comparator.reverseOrder());
        for (int i = 0; i < nums.length; ++i) {
            d.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        int ans = 0, k = 1 << 30;
        for (List<Integer> idx : d.values()) {
            ans = Math.max(ans, idx.get(idx.size() - 1) - k + 1);
            k = Math.min(k, idx.get(0));
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
    int maxSubarrayLength(vector<int>& nums) {
        map<int, vector<int>, greater<int>> d;
        for (int i = 0; i < nums.size(); ++i) {
            d[nums[i]].push_back(i);
        }
        int ans = 0, k = 1 << 30;
        for (auto& [_, idx] : d) {
            ans = max(ans, idx.back() - k + 1);
            k = min(k, idx[0]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubarrayLength(nums []int) (ans int) {
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	keys := []int{}
	for x := range d {
		keys = append(keys, x)
	}
	sort.Slice(keys, func(i, j int) bool { return keys[i] > keys[j] })
	k := 1 << 30
	for _, x := range keys {
		idx := d[x]
		ans = max(ans, idx[len(idx)-1]-k+1)
		k = min(k, idx[0])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubarrayLength(nums: number[]): number {
    const d: Map<number, number[]> = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (!d.has(nums[i])) {
            d.set(nums[i], []);
        }
        d.get(nums[i])!.push(i);
    }
    const keys = Array.from(d.keys()).sort((a, b) => b - a);
    let ans = 0;
    let k = Infinity;
    for (const x of keys) {
        const idx = d.get(x)!;
        ans = Math.max(ans, idx.at(-1) - k + 1);
        k = Math.min(k, idx[0]);
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

<p>给定一个整数数组 <code>nums</code>。</p>

<p>返回 <code>nums</code> 的&nbsp;<em><strong>最长半递减子数组&nbsp;</strong></em>的长度，如果没有这样的子数组则返回 <code>0</code>。</p>

<ul>
	<li><strong>子数组</strong> 是数组内的连续非空元素序列。</li>
	<li>一个非空数组是 <strong>半递减</strong> 的，如果它的第一个元素 <strong>严格大于</strong> 它的最后一个元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> nums = [7,6,5,4,3,2,1,6,10,11]
<b>输出：</b> 8
<b>解释：</b> 取子数组 [7,6,5,4,3,2,1,6]。
第一个元素是 7，最后一个元素是 6，因此满足条件。
因此，答案是子数组的长度，即 8。
可以证明，在给定条件下，没有长度大于 8 的子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b> nums = [57,55,50,60,61,58,63,59,64,60,63]
<b>输出：</b> 6
<b>解释：</b> 取子数组 [61,58,63,59,64,60].
第一个元素是 61，最后一个元素是 60，因此满足条件。
因此，答案是子数组的长度，即 6。
可以证明，在给定条件下，没有长度大于 6 的子数组。
</pre>

<p><b>示例 3:</b></p>

<pre>
<b>输入：</b> nums = [1,2,3,4]
<b>输出：</b> 0
<b>解释：</b> 由于给定数组中没有半递减子数组，答案为 0。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

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

### 方法一：哈希表 + 排序

题目实际上是求逆序对的最大长度，我们不妨用哈希表 $d$ 记录数组中每个数字 $x$ 对应的下标 $i$。

接下来，我们按照数字从大到小的顺序遍历哈希表的键，用一个数字 $k$ 维护此前出现过的最小的下标，那么对于当前的数字 $x$，我们可以得到一个最大的逆序对长度 $d[x][|d[x]|-1]-k + 1$，其中 $|d[x]|$ 表示数组 $d[x]$ 的长度，即数字 $x$ 在原数组中出现的次数，我们更新答案即可。然后，我们将 $k$ 更新为 $d[x][0]$，即数字 $x$ 在原数组中第一次出现的下标。继续遍历哈希表的键，直到遍历完所有的键。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubarrayLength(self, nums: List[int]) -> int:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans, k = 0, inf
        for x in sorted(d, reverse=True):
            ans = max(ans, d[x][-1] - k + 1)
            k = min(k, d[x][0])
        return ans
```

#### Java

```java
class Solution {
    public int maxSubarrayLength(int[] nums) {
        TreeMap<Integer, List<Integer>> d = new TreeMap<>(Comparator.reverseOrder());
        for (int i = 0; i < nums.length; ++i) {
            d.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        int ans = 0, k = 1 << 30;
        for (List<Integer> idx : d.values()) {
            ans = Math.max(ans, idx.get(idx.size() - 1) - k + 1);
            k = Math.min(k, idx.get(0));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        map<int, vector<int>, greater<int>> d;
        for (int i = 0; i < nums.size(); ++i) {
            d[nums[i]].push_back(i);
        }
        int ans = 0, k = 1 << 30;
        for (auto& [_, idx] : d) {
            ans = max(ans, idx.back() - k + 1);
            k = min(k, idx[0]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubarrayLength(nums []int) (ans int) {
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	keys := []int{}
	for x := range d {
		keys = append(keys, x)
	}
	sort.Slice(keys, func(i, j int) bool { return keys[i] > keys[j] })
	k := 1 << 30
	for _, x := range keys {
		idx := d[x]
		ans = max(ans, idx[len(idx)-1]-k+1)
		k = min(k, idx[0])
	}
	return ans
}
```

#### TypeScript

```ts
function maxSubarrayLength(nums: number[]): number {
    const d: Map<number, number[]> = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (!d.has(nums[i])) {
            d.set(nums[i], []);
        }
        d.get(nums[i])!.push(i);
    }
    const keys = Array.from(d.keys()).sort((a, b) => b - a);
    let ans = 0;
    let k = Infinity;
    for (const x of keys) {
        const idx = d.get(x)!;
        ans = Math.max(ans, idx.at(-1) - k + 1);
        k = Math.min(k, idx[0]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2864. 最大二进制奇数](https://leetcode.cn/problems/maximum-odd-binary-number){#2864}

{{< tabs "2864" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt = s.count("1")
        return "1" * (cnt - 1) + (len(s) - cnt) * "0" + "1"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        int cnt = s.length() - s.replace("1", "").length();
        return "1".repeat(cnt - 1) + "0".repeat(s.length() - cnt) + "1";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.size() - cnt, '0') + '1';
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumOddBinaryNumber(s string) string {
	cnt := strings.Count(s, "1")
	return strings.Repeat("1", cnt-1) + strings.Repeat("0", len(s)-cnt) + "1"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumOddBinaryNumber(s: string): string {
    const cnt = s.length - s.replace(/1/g, '').length;
    return '1'.repeat(cnt - 1) + '0'.repeat(s.length - cnt) + '1';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let cnt = s.chars().filter(|&c| c == '1').count();
        "1".repeat(cnt - 1) + &"0".repeat(s.len() - cnt) + "1"
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>二进制</strong> 字符串 <code>s</code> ，其中至少包含一个 <code>'1'</code> 。</p>

<p>你必须按某种方式 <strong>重新排列</strong> 字符串中的位，使得到的二进制数字是可以由该组合生成的 <strong>最大二进制奇数</strong> 。</p>

<p>以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。</p>

<p><strong>注意 </strong>返回的结果字符串 <strong>可以</strong> 含前导零。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "010"
<strong>输出：</strong>"001"
<strong>解释：</strong>因为字符串 s 中仅有一个 '1' ，其必须出现在最后一位上。所以答案是 "001" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0101"
<strong>输出：</strong>"1001"
<strong>解释：</strong>其中一个 '1' 必须出现在最后一位上。而由剩下的数字可以生产的最大数字是 "100" 。所以答案是 "1001" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由 <code>'0'</code> 和 <code>'1'</code> 组成</li>
	<li><code>s</code> 中至少包含一个 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先统计字符串 $s$ 中 $1$ 的个数，记为 $cnt$。那么我们将 $cnt - 1$ 个 $1$ 放在最高位，剩下的 $|s| - cnt$ 个 $0$ 放在后面，最后再加上一个 $1$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt = s.count("1")
        return "1" * (cnt - 1) + (len(s) - cnt) * "0" + "1"
```

#### Java

```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        int cnt = s.length() - s.replace("1", "").length();
        return "1".repeat(cnt - 1) + "0".repeat(s.length() - cnt) + "1";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.size() - cnt, '0') + '1';
    }
};
```

#### Go

```go
func maximumOddBinaryNumber(s string) string {
	cnt := strings.Count(s, "1")
	return strings.Repeat("1", cnt-1) + strings.Repeat("0", len(s)-cnt) + "1"
}
```

#### TypeScript

```ts
function maximumOddBinaryNumber(s: string): string {
    const cnt = s.length - s.replace(/1/g, '').length;
    return '1'.repeat(cnt - 1) + '0'.repeat(s.length - cnt) + '1';
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let cnt = s.chars().filter(|&c| c == '1').count();
        "1".repeat(cnt - 1) + &"0".repeat(s.len() - cnt) + "1"
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2865. 美丽塔 I](https://leetcode.cn/problems/beautiful-towers-i){#2865}

{{< tabs "2865" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        stk = []
        left = [-1] * n
        for i, x in enumerate(maxHeights):
            while stk and maxHeights[stk[-1]] > x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        right = [n] * n
        for i in range(n - 1, -1, -1):
            x = maxHeights[i]
            while stk and maxHeights[stk[-1]] >= x:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        f = [0] * n
        for i, x in enumerate(maxHeights):
            if i and x >= maxHeights[i - 1]:
                f[i] = f[i - 1] + x
            else:
                j = left[i]
                f[i] = x * (i - j) + (f[j] if j != -1 else 0)
        g = [0] * n
        for i in range(n - 1, -1, -1):
            if i < n - 1 and maxHeights[i] >= maxHeights[i + 1]:
                g[i] = g[i + 1] + maxHeights[i]
            else:
                j = right[i]
                g[i] = maxHeights[i] * (j - i) + (g[j] if j != n else 0)
        return max(a + b - c for a, b, c in zip(f, g, maxHeights))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) >= x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] f = new long[n];
        long[] g = new long[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            if (i > 0 && x >= maxHeights.get(i - 1)) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1L * x * (i - j) + (j >= 0 ? f[j] : 0);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            if (i < n - 1 && x >= maxHeights.get(i + 1)) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1L * x * (j - i) + (j < n ? g[j] : 0);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i] + g[i] - maxHeights.get(i));
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] >= x) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long f[n], g[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1]) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1LL * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1]) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1LL * x * (j - i) + (j != n ? g[j] : 0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[i] - maxHeights[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	stk := []int{}
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	for i, x := range maxHeights {
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	g := make([]int64, n)
	for i, x := range maxHeights {
		if i > 0 && x >= maxHeights[i-1] {
			f[i] = f[i-1] + int64(x)
		} else {
			j := left[i]
			f[i] = int64(x) * int64(i-j)
			if j != -1 {
				f[i] += f[j]
			}
		}
	}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		if i < n-1 && x >= maxHeights[i+1] {
			g[i] = g[i+1] + int64(x)
		} else {
			j := right[i]
			g[i] = int64(x) * int64(j-i)
			if j != n {
				g[i] += g[j]
			}
		}
	}
	for i, x := range maxHeights {
		ans = max(ans, f[i]+g[i]-int64(x))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSumOfHeights(maxHeights: number[]): number {
    const n = maxHeights.length;
    const stk: number[] = [];
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] > x) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] >= x) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        if (i && x >= maxHeights[i - 1]) {
            f[i] = f[i - 1] + x;
        } else {
            const j = left[i];
            f[i] = x * (i - j) + (j >= 0 ? f[j] : 0);
        }
    }
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        if (i + 1 < n && x >= maxHeights[i + 1]) {
            g[i] = g[i + 1] + x;
        } else {
            const j = right[i];
            g[i] = x * (j - i) + (j < n ? g[j] : 0);
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i] + g[i] - maxHeights[i]);
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

<p>给定一个包含&nbsp;<code>n</code>&nbsp;个整数的数组&nbsp;<code>heights</code>&nbsp;表示&nbsp;<code>n</code>&nbsp;座连续的塔中砖块的数量。你的任务是移除一些砖块来形成一个 <strong>山脉状</strong> 的塔排列。在这种布置中，塔高度先是非递减，有一个或多个连续塔达到最大峰值，然后非递增排列。</p>

<p>返回满足山脉状塔排列的方案中，<strong>高度和的最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>maxHeights = [5,3,4,1,1]
<b>输出：</b>13
<b>解释：</b>我们移除一些砖块来形成 heights = [5,3,3,1,1]，峰值位于下标 0。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>maxHeights = [6,5,3,9,2,7]
<b>输出：</b>22
<strong>解释：</strong>我们移除一些砖块来形成 heights = [3,3,3,9,2,2]，峰值位于下标 3。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>maxHeights = [3,2,5,5,2,3]
<b>输出：</b>18
<strong>解释：</strong>我们移除一些砖块来形成 heights = [2,2,5,5,2,2]，峰值位于下标 2 或 3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == heights.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每一座塔作为最高塔，每一次向左右两边扩展，算出其他每个位置的高度，然后累加得到高度和 $t$。求出所有高度和的最大值即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $maxHeights$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        ans, n = 0, len(maxHeights)
        for i, x in enumerate(maxHeights):
            y = t = x
            for j in range(i - 1, -1, -1):
                y = min(y, maxHeights[j])
                t += y
            y = x
            for j in range(i + 1, n):
                y = min(y, maxHeights[j])
                t += y
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        long ans = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {
            int y = maxHeights.get(i);
            long t = y;
            for (int j = i - 1; j >= 0; --j) {
                y = Math.min(y, maxHeights.get(j));
                t += y;
            }
            y = maxHeights.get(i);
            for (int j = i + 1; j < n; ++j) {
                y = Math.min(y, maxHeights.get(j));
                t += y;
            }
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {
            long long t = maxHeights[i];
            int y = t;
            for (int j = i - 1; ~j; --j) {
                y = min(y, maxHeights[j]);
                t += y;
            }
            y = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                y = min(y, maxHeights[j]);
                t += y;
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	for i, x := range maxHeights {
		y, t := x, x
		for j := i - 1; j >= 0; j-- {
			y = min(y, maxHeights[j])
			t += y
		}
		y = x
		for j := i + 1; j < n; j++ {
			y = min(y, maxHeights[j])
			t += y
		}
		ans = max(ans, int64(t))
	}
	return
}
```

#### TypeScript

```ts
function maximumSumOfHeights(maxHeights: number[]): number {
    let ans = 0;
    const n = maxHeights.length;
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        let [y, t] = [x, x];
        for (let j = i - 1; ~j; --j) {
            y = Math.min(y, maxHeights[j]);
            t += y;
        }
        y = x;
        for (let j = i + 1; j < n; ++j) {
            y = Math.min(y, maxHeights[j]);
            t += y;
        }
        ans = Math.max(ans, t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 单调栈

方法一的做法足以通过本题，但是时间复杂度较高。我们可以使用“动态规划 + 单调栈”来优化枚举的过程。

我们定义 $f[i]$ 表示前 $i+1$ 座塔中，以最后一座塔作为最高塔的美丽塔方案的高度和。我们可以得到如下的状态转移方程：

$$
f[i]=
\begin{cases}
f[i-1]+heights[i],&\textit{if } heights[i]\geq heights[i-1]\\
heights[i]\times(i-j)+f[j],&\textit{if } heights[i]<heights[i-1]
\end{cases}
$$

其中 $j$ 是最后一座塔左边第一个高度小于等于 $heights[i]$ 的塔的下标。我们可以使用单调栈来维护这个下标。

我们可以使用类似的方法求出 $g[i]$，表示从右往左，以第 $i$ 座塔作为最高塔的美丽塔方案的高度和。最终答案即为 $f[i]+g[i]-heights[i]$ 的最大值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $maxHeights$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        stk = []
        left = [-1] * n
        for i, x in enumerate(maxHeights):
            while stk and maxHeights[stk[-1]] > x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        right = [n] * n
        for i in range(n - 1, -1, -1):
            x = maxHeights[i]
            while stk and maxHeights[stk[-1]] >= x:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        f = [0] * n
        for i, x in enumerate(maxHeights):
            if i and x >= maxHeights[i - 1]:
                f[i] = f[i - 1] + x
            else:
                j = left[i]
                f[i] = x * (i - j) + (f[j] if j != -1 else 0)
        g = [0] * n
        for i in range(n - 1, -1, -1):
            if i < n - 1 and maxHeights[i] >= maxHeights[i + 1]:
                g[i] = g[i + 1] + maxHeights[i]
            else:
                j = right[i]
                g[i] = maxHeights[i] * (j - i) + (g[j] if j != n else 0)
        return max(a + b - c for a, b, c in zip(f, g, maxHeights))
```

#### Java

```java
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) >= x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] f = new long[n];
        long[] g = new long[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            if (i > 0 && x >= maxHeights.get(i - 1)) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1L * x * (i - j) + (j >= 0 ? f[j] : 0);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            if (i < n - 1 && x >= maxHeights.get(i + 1)) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1L * x * (j - i) + (j < n ? g[j] : 0);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i] + g[i] - maxHeights.get(i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] >= x) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long f[n], g[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1]) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1LL * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1]) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1LL * x * (j - i) + (j != n ? g[j] : 0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[i] - maxHeights[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	stk := []int{}
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	for i, x := range maxHeights {
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	g := make([]int64, n)
	for i, x := range maxHeights {
		if i > 0 && x >= maxHeights[i-1] {
			f[i] = f[i-1] + int64(x)
		} else {
			j := left[i]
			f[i] = int64(x) * int64(i-j)
			if j != -1 {
				f[i] += f[j]
			}
		}
	}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		if i < n-1 && x >= maxHeights[i+1] {
			g[i] = g[i+1] + int64(x)
		} else {
			j := right[i]
			g[i] = int64(x) * int64(j-i)
			if j != n {
				g[i] += g[j]
			}
		}
	}
	for i, x := range maxHeights {
		ans = max(ans, f[i]+g[i]-int64(x))
	}
	return
}
```

#### TypeScript

```ts
function maximumSumOfHeights(maxHeights: number[]): number {
    const n = maxHeights.length;
    const stk: number[] = [];
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] > x) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] >= x) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        if (i && x >= maxHeights[i - 1]) {
            f[i] = f[i - 1] + x;
        } else {
            const j = left[i];
            f[i] = x * (i - j) + (j >= 0 ? f[j] : 0);
        }
    }
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        if (i + 1 < n && x >= maxHeights[i + 1]) {
            g[i] = g[i + 1] + x;
        } else {
            const j = right[i];
            g[i] = x * (j - i) + (j < n ? g[j] : 0);
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i] + g[i] - maxHeights[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2866. 美丽塔 II](https://leetcode.cn/problems/beautiful-towers-ii){#2866}

{{< tabs "2866" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        stk = []
        left = [-1] * n
        for i, x in enumerate(maxHeights):
            while stk and maxHeights[stk[-1]] > x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        right = [n] * n
        for i in range(n - 1, -1, -1):
            x = maxHeights[i]
            while stk and maxHeights[stk[-1]] >= x:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        f = [0] * n
        for i, x in enumerate(maxHeights):
            if i and x >= maxHeights[i - 1]:
                f[i] = f[i - 1] + x
            else:
                j = left[i]
                f[i] = x * (i - j) + (f[j] if j != -1 else 0)
        g = [0] * n
        for i in range(n - 1, -1, -1):
            if i < n - 1 and maxHeights[i] >= maxHeights[i + 1]:
                g[i] = g[i + 1] + maxHeights[i]
            else:
                j = right[i]
                g[i] = maxHeights[i] * (j - i) + (g[j] if j != n else 0)
        return max(a + b - c for a, b, c in zip(f, g, maxHeights))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) >= x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] f = new long[n];
        long[] g = new long[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            if (i > 0 && x >= maxHeights.get(i - 1)) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1L * x * (i - j) + (j >= 0 ? f[j] : 0);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            if (i < n - 1 && x >= maxHeights.get(i + 1)) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1L * x * (j - i) + (j < n ? g[j] : 0);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i] + g[i] - maxHeights.get(i));
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] >= x) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long f[n], g[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1]) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1LL * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1]) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1LL * x * (j - i) + (j != n ? g[j] : 0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[i] - maxHeights[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	stk := []int{}
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	for i, x := range maxHeights {
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	g := make([]int64, n)
	for i, x := range maxHeights {
		if i > 0 && x >= maxHeights[i-1] {
			f[i] = f[i-1] + int64(x)
		} else {
			j := left[i]
			f[i] = int64(x) * int64(i-j)
			if j != -1 {
				f[i] += f[j]
			}
		}
	}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		if i < n-1 && x >= maxHeights[i+1] {
			g[i] = g[i+1] + int64(x)
		} else {
			j := right[i]
			g[i] = int64(x) * int64(j-i)
			if j != n {
				g[i] += g[j]
			}
		}
	}
	for i, x := range maxHeights {
		ans = max(ans, f[i]+g[i]-int64(x))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSumOfHeights(maxHeights: number[]): number {
    const n = maxHeights.length;
    const stk: number[] = [];
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] > x) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] >= x) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        if (i && x >= maxHeights[i - 1]) {
            f[i] = f[i - 1] + x;
        } else {
            const j = left[i];
            f[i] = x * (i - j) + (j >= 0 ? f[j] : 0);
        }
    }
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        if (i + 1 < n && x >= maxHeights[i + 1]) {
            g[i] = g[i + 1] + x;
        } else {
            const j = right[i];
            g[i] = x * (j - i) + (j < n ? g[j] : 0);
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i] + g[i] - maxHeights[i]);
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>maxHeights</code>&nbsp;。</p>

<p>你的任务是在坐标轴上建 <code>n</code>&nbsp;座塔。第&nbsp;<code>i</code>&nbsp;座塔的下标为 <code>i</code>&nbsp;，高度为&nbsp;<code>heights[i]</code>&nbsp;。</p>

<p>如果以下条件满足，我们称这些塔是 <strong>美丽</strong>&nbsp;的：</p>

<ol>
	<li><code>1 &lt;= heights[i] &lt;= maxHeights[i]</code></li>
	<li><code>heights</code>&nbsp;是一个 <strong>山脉</strong> 数组。</li>
</ol>

<p>如果存在下标 <code>i</code>&nbsp;满足以下条件，那么我们称数组&nbsp;<code>heights</code>&nbsp;是一个 <strong>山脉</strong> 数组：</p>

<ul>
	<li>对于所有&nbsp;<code>0 &lt; j &lt;= i</code>&nbsp;，都有&nbsp;<code>heights[j - 1] &lt;= heights[j]</code></li>
	<li>对于所有&nbsp;<code>i &lt;= k &lt; n - 1</code>&nbsp;，都有&nbsp;<code>heights[k + 1] &lt;= heights[k]</code></li>
</ul>

<p>请你返回满足 <b>美丽塔</b>&nbsp;要求的方案中，<strong>高度和的最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>maxHeights = [5,3,4,1,1]
<b>输出：</b>13
<b>解释：</b>和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
- 1 &lt;= heights[i] &lt;= maxHeights[i]  
- heights 是个山脉数组，峰值在 i = 0 处。
13 是所有美丽塔方案中的最大高度和。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>maxHeights = [6,5,3,9,2,7]
<b>输出：</b>22
<strong>解释：</strong> 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
- 1 &lt;= heights[i] &lt;= maxHeights[i]
- heights 是个山脉数组，峰值在 i = 3 处。
22 是所有美丽塔方案中的最大高度和。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>maxHeights = [3,2,5,5,2,3]
<b>输出：</b>18
<strong>解释：</strong>和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
- 1 &lt;= heights[i] &lt;= maxHeights[i]
- heights 是个山脉数组，最大值在 i = 2 处。
注意，在这个方案中，i = 3 也是一个峰值。
18 是所有美丽塔方案中的最大高度和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == maxHeights&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= maxHeights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 单调栈

我们定义 $f[i]$ 表示前 $i+1$ 座塔中，以最后一座塔作为最高塔的美丽塔方案的高度和。我们可以得到如下的状态转移方程：

$$
f[i]=
\begin{cases}
f[i-1]+heights[i],&\textit{if } heights[i]\geq heights[i-1]\\
heights[i]\times(i-j)+f[j],&\textit{if } heights[i]<heights[i-1]
\end{cases}
$$

其中 $j$ 是最后一座塔左边第一个高度小于等于 $heights[i]$ 的塔的下标。我们可以使用单调栈来维护这个下标。

我们可以使用类似的方法求出 $g[i]$，表示从右往左，以第 $i$ 座塔作为最高塔的美丽塔方案的高度和。最终答案即为 $f[i]+g[i]-heights[i]$ 的最大值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $maxHeights$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        stk = []
        left = [-1] * n
        for i, x in enumerate(maxHeights):
            while stk and maxHeights[stk[-1]] > x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        right = [n] * n
        for i in range(n - 1, -1, -1):
            x = maxHeights[i]
            while stk and maxHeights[stk[-1]] >= x:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        f = [0] * n
        for i, x in enumerate(maxHeights):
            if i and x >= maxHeights[i - 1]:
                f[i] = f[i - 1] + x
            else:
                j = left[i]
                f[i] = x * (i - j) + (f[j] if j != -1 else 0)
        g = [0] * n
        for i in range(n - 1, -1, -1):
            if i < n - 1 and maxHeights[i] >= maxHeights[i + 1]:
                g[i] = g[i + 1] + maxHeights[i]
            else:
                j = right[i]
                g[i] = maxHeights[i] * (j - i) + (g[j] if j != n else 0)
        return max(a + b - c for a, b, c in zip(f, g, maxHeights))
```

#### Java

```java
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            while (!stk.isEmpty() && maxHeights.get(stk.peek()) >= x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] f = new long[n];
        long[] g = new long[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights.get(i);
            if (i > 0 && x >= maxHeights.get(i - 1)) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1L * x * (i - j) + (j >= 0 ? f[j] : 0);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = maxHeights.get(i);
            if (i < n - 1 && x >= maxHeights.get(i + 1)) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1L * x * (j - i) + (j < n ? g[j] : 0);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i] + g[i] - maxHeights.get(i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            while (!stk.empty() && maxHeights[stk.top()] >= x) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long f[n], g[n];
        for (int i = 0; i < n; ++i) {
            int x = maxHeights[i];
            if (i && x >= maxHeights[i - 1]) {
                f[i] = f[i - 1] + x;
            } else {
                int j = left[i];
                f[i] = 1LL * x * (i - j) + (j != -1 ? f[j] : 0);
            }
        }
        for (int i = n - 1; ~i; --i) {
            int x = maxHeights[i];
            if (i < n - 1 && x >= maxHeights[i + 1]) {
                g[i] = g[i + 1] + x;
            } else {
                int j = right[i];
                g[i] = 1LL * x * (j - i) + (j != n ? g[j] : 0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[i] - maxHeights[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSumOfHeights(maxHeights []int) (ans int64) {
	n := len(maxHeights)
	stk := []int{}
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	for i, x := range maxHeights {
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		for len(stk) > 0 && maxHeights[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	g := make([]int64, n)
	for i, x := range maxHeights {
		if i > 0 && x >= maxHeights[i-1] {
			f[i] = f[i-1] + int64(x)
		} else {
			j := left[i]
			f[i] = int64(x) * int64(i-j)
			if j != -1 {
				f[i] += f[j]
			}
		}
	}
	for i := n - 1; i >= 0; i-- {
		x := maxHeights[i]
		if i < n-1 && x >= maxHeights[i+1] {
			g[i] = g[i+1] + int64(x)
		} else {
			j := right[i]
			g[i] = int64(x) * int64(j-i)
			if j != n {
				g[i] += g[j]
			}
		}
	}
	for i, x := range maxHeights {
		ans = max(ans, f[i]+g[i]-int64(x))
	}
	return
}
```

#### TypeScript

```ts
function maximumSumOfHeights(maxHeights: number[]): number {
    const n = maxHeights.length;
    const stk: number[] = [];
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] > x) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        while (stk.length && maxHeights[stk.at(-1)] >= x) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const x = maxHeights[i];
        if (i && x >= maxHeights[i - 1]) {
            f[i] = f[i - 1] + x;
        } else {
            const j = left[i];
            f[i] = x * (i - j) + (j >= 0 ? f[j] : 0);
        }
    }
    for (let i = n - 1; ~i; --i) {
        const x = maxHeights[i];
        if (i + 1 < n && x >= maxHeights[i + 1]) {
            g[i] = g[i + 1] + x;
        } else {
            const j = right[i];
            g[i] = x * (j - i) + (j < n ? g[j] : 0);
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i] + g[i] - maxHeights[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2867. 统计树中的合法路径数目](https://leetcode.cn/problems/count-valid-paths-in-a-tree){#2867}

{{< tabs "2867" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPaths(self, n: int, edges: List[List[int]]) -> int:
        def mul(x, y):
            return x * y

        def dfs(x, f, con, prime, r):
            v = [1 - prime[x], prime[x]]
            for y in con[x]:
                if y == f:
                    continue
                p = dfs(y, x, con, prime, r)
                r[0] += mul(p[0], v[1]) + mul(p[1], v[0])
                if prime[x]:
                    v[1] += p[0]
                else:
                    v[0] += p[0]
                    v[1] += p[1]
            return v

        prime = [True] * (n + 1)
        prime[1] = False

        all_primes = []
        for i in range(2, n + 1):
            if prime[i]:
                all_primes.append(i)
            for x in all_primes:
                temp = i * x
                if temp > n:
                    break
                prime[temp] = False
                if i % x == 0:
                    break

        con = [[] for _ in range(n + 1)]
        for e in edges:
            con[e[0]].append(e[1])
            con[e[1]].append(e[0])

        r = [0]
        dfs(1, 0, con, prime, r)
        return r[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countPaths(int n, int[][] edges) {
        List<Boolean> prime = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; ++i) {
            prime.add(true);
        }
        prime.set(1, false);

        List<Integer> all = new ArrayList<>();
        for (int i = 2; i <= n; ++i) {
            if (prime.get(i)) {
                all.add(i);
            }
            for (int x : all) {
                int temp = i * x;
                if (temp > n) {
                    break;
                }
                prime.set(temp, false);
                if (i % x == 0) {
                    break;
                }
            }
        }

        List<List<Integer>> con = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; ++i) {
            con.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            con.get(e[0]).add(e[1]);
            con.get(e[1]).add(e[0]);
        }

        long[] r = {0};
        dfs(1, 0, con, prime, r);
        return r[0];
    }

    private long mul(long x, long y) {
        return x * y;
    }

    private class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    private Pair dfs(int x, int f, List<List<Integer>> con, List<Boolean> prime, long[] r) {
        Pair v = new Pair(!prime.get(x) ? 1 : 0, prime.get(x) ? 1 : 0);
        for (int y : con.get(x)) {
            if (y == f) continue;
            Pair p = dfs(y, x, con, prime, r);
            r[0] += mul(p.first, v.second) + mul(p.second, v.first);
            if (prime.get(x)) {
                v.second += p.first;
            } else {
                v.first += p.first;
                v.second += p.second;
            }
        }
        return v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
    long long mul(long long x, long long y) {
        return x * y;
    }

    pair<int, int> dfs(int x, int f, const vector<vector<int>>& con, const vector<bool>& prime, long long& r) {
        pair<int, int> v = {!prime[x], prime[x]};
        for (int y : con[x]) {
            if (y == f) continue;
            const auto& p = dfs(y, x, con, prime, r);
            r += mul(p.first, v.second) + mul(p.second, v.first);
            if (prime[x]) {
                v.second += p.first;
            } else {
                v.first += p.first;
                v.second += p.second;
            }
        }
        return v;
    }

public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> prime(n + 1, true);
        prime[1] = false;
        vector<int> all;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                all.push_back(i);
            }
            for (int x : all) {
                const int temp = i * x;
                if (temp > n) {
                    break;
                }
                prime[temp] = false;
                if (i % x == 0) {
                    break;
                }
            }
        }
        vector<vector<int>> con(n + 1);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        long long r = 0;
        dfs(1, 0, con, prime, r);
        return r;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mx int = 1e5 + 10

var prime [mx]bool

func init() {
	for i := 2; i < mx; i++ {
		prime[i] = true
	}
	for i := 2; i < mx; i++ {
		if prime[i] {
			for j := i + i; j < mx; j += i {
				prime[j] = false
			}
		}
	}
}

type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(x int) int {
	return uf.size[uf.find(x)]
}

func countPaths(n int, edges [][]int) (ans int64) {
	uf := newUnionFind(n + 1)
	g := make([][]int, n+1)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
		if !prime[u] && !prime[v] {
			uf.union(u, v)
		}
	}
	for i := 1; i <= n; i++ {
		if prime[i] {
			t := 0
			for _, j := range g[i] {
				if !prime[j] {
					cnt := uf.getSize(j)
					ans += int64(cnt + cnt*t)
					t += cnt
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
const mx = 100010;
const prime = Array(mx).fill(true);
prime[0] = prime[1] = false;
for (let i = 2; i <= mx; ++i) {
    if (prime[i]) {
        for (let j = i + i; j <= mx; j += i) {
            prime[j] = false;
        }
    }
}

class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(x: number): number {
        return this.size[this.find(x)];
    }
}

function countPaths(n: number, edges: number[][]): number {
    const uf = new UnionFind(n + 1);
    const g: number[][] = Array(n + 1)
        .fill(0)
        .map(() => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
        if (!prime[u] && !prime[v]) {
            uf.union(u, v);
        }
    }
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        if (prime[i]) {
            let t = 0;
            for (let j of g[i]) {
                if (!prime[j]) {
                    const cnt = uf.getSize(j);
                    ans += cnt + t * cnt;
                    t += cnt;
                }
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

<p>给你一棵 <code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。给你一个整数&nbsp;<code>n</code>&nbsp;和一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code>&nbsp;在树中有一条边。</p>

<p>请你返回树中的 <strong>合法路径数目</strong>&nbsp;。</p>

<p>如果在节点 <code>a</code>&nbsp;到节点 <code>b</code>&nbsp;之间 <strong>恰好有一个</strong>&nbsp;节点的编号是质数，那么我们称路径&nbsp;<code>(a, b)</code>&nbsp;是 <strong>合法的</strong>&nbsp;。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>路径&nbsp;<code>(a, b)</code>&nbsp;指的是一条从节点 <code>a</code>&nbsp;开始到节点 <code>b</code>&nbsp;结束的一个节点序列，序列中的节点 <strong>互不相同</strong>&nbsp;，且相邻节点之间在树上有一条边。</li>
	<li>路径&nbsp;<code>(a, b)</code>&nbsp;和路径&nbsp;<code>(b, a)</code>&nbsp;视为 <strong>同一条</strong>&nbsp;路径，且只计入答案 <strong>一次</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2867.Count%20Valid%20Paths%20in%20a%20Tree/images/example1.png" style="width: 440px; height: 357px;" /></p>

<pre>
<b>输入：</b>n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
<b>输出：</b>4
<b>解释：</b>恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
只有 4 条合法路径。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2867.Count%20Valid%20Paths%20in%20a%20Tree/images/example2.png" style="width: 488px; height: 384px;" /></p>

<pre>
<b>输入：</b>n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
<b>输出：</b>6
<b>解释：</b>恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (1, 6) 因为路径 1 到 6 只包含一个质数 3 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
- (3, 6) 因为路径 3 到 6 只包含一个质数 3 。
只有 6 条合法路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;形成一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 并查集 + 枚举

我们可以预处理得到 $[1, n]$ 中的所有质数，其中 $prime[i]$ 表示 $i$ 是否为质数。

接下来，我们根据二维整数整数构建图 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻居节点。如果一条边的两个节点都不是质数，那么我们就将这两个节点合并到同一个连通分量中。

然后，我们在 $[1, n]$ 的范围内枚举所有质数 $i$，考虑包含 $i$ 的所有路径。

由于 $i$ 已经是质数，如果 $i$ 是路径的一个端点，那么我们只需要累计与节点 $i$ 相邻的所有连通分量的大小即可。如果 $i$ 是路径上的某个中间点，那么我们需要累计相邻的任意两个连通分量的大小之积。

时间复杂度 $O(n \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 为节点数，而 $\alpha$ 为阿克曼函数的反函数。

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


mx = 10**5 + 10
prime = [True] * (mx + 1)
prime[0] = prime[1] = False
for i in range(2, mx + 1):
    if prime[i]:
        for j in range(i * i, mx + 1, i):
            prime[j] = False


class Solution:
    def countPaths(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n + 1)]
        uf = UnionFind(n + 1)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
            if prime[u] + prime[v] == 0:
                uf.union(u, v)

        ans = 0
        for i in range(1, n + 1):
            if prime[i]:
                t = 0
                for j in g[i]:
                    if not prime[j]:
                        cnt = uf.size[uf.find(j)]
                        ans += cnt
                        ans += t * cnt
                        t += cnt
        return ans
```

#### Java

```java
class PrimeTable {
    private final boolean[] prime;

    public PrimeTable(int n) {
        prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                for (int j = i + i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    public boolean isPrime(int x) {
        return prime[x];
    }
}

class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int x) {
        return size[find(x)];
    }
}

class Solution {
    private static final PrimeTable PT = new PrimeTable(100010);

    public long countPaths(int n, int[][] edges) {
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        UnionFind uf = new UnionFind(n + 1);
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
            if (!PT.isPrime(u) && !PT.isPrime(v)) {
                uf.union(u, v);
            }
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (PT.isPrime(i)) {
                long t = 0;
                for (int j : g[i]) {
                    if (!PT.isPrime(j)) {
                        long cnt = uf.size(j);
                        ans += cnt;
                        ans += cnt * t;
                        t += cnt;
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
const int mx = 1e5 + 10;
bool prime[mx + 1];
int init = []() {
    for (int i = 2; i <= mx; ++i) prime[i] = true;
    for (int i = 2; i <= mx; ++i) {
        if (prime[i]) {
            for (int j = i + i; j <= mx; j += i) {
                prime[j] = false;
            }
        }
    }
    return 0;
}();

class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int x) {
        return size[find(x)];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<int> g[n + 1];
        UnionFind uf(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            if (!prime[u] && !prime[v]) {
                uf.unite(u, v);
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (prime[i]) {
                long long t = 0;
                for (int j : g[i]) {
                    if (!prime[j]) {
                        long long cnt = uf.getSize(j);
                        ans += cnt;
                        ans += cnt * t;
                        t += cnt;
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
const mx int = 1e5 + 10

var prime [mx]bool

func init() {
	for i := 2; i < mx; i++ {
		prime[i] = true
	}
	for i := 2; i < mx; i++ {
		if prime[i] {
			for j := i + i; j < mx; j += i {
				prime[j] = false
			}
		}
	}
}

type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(x int) int {
	return uf.size[uf.find(x)]
}

func countPaths(n int, edges [][]int) (ans int64) {
	uf := newUnionFind(n + 1)
	g := make([][]int, n+1)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
		if !prime[u] && !prime[v] {
			uf.union(u, v)
		}
	}
	for i := 1; i <= n; i++ {
		if prime[i] {
			t := 0
			for _, j := range g[i] {
				if !prime[j] {
					cnt := uf.getSize(j)
					ans += int64(cnt + cnt*t)
					t += cnt
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
const mx = 100010;
const prime = Array(mx).fill(true);
prime[0] = prime[1] = false;
for (let i = 2; i <= mx; ++i) {
    if (prime[i]) {
        for (let j = i + i; j <= mx; j += i) {
            prime[j] = false;
        }
    }
}

class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(x: number): number {
        return this.size[this.find(x)];
    }
}

function countPaths(n: number, edges: number[][]): number {
    const uf = new UnionFind(n + 1);
    const g: number[][] = Array(n + 1)
        .fill(0)
        .map(() => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
        if (!prime[u] && !prime[v]) {
            uf.union(u, v);
        }
    }
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        if (prime[i]) {
            let t = 0;
            for (let j of g[i]) {
                if (!prime[j]) {
                    const cnt = uf.getSize(j);
                    ans += cnt + t * cnt;
                    t += cnt;
                }
            }
        }
    }
    return ans;
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
    def countPaths(self, n: int, edges: List[List[int]]) -> int:
        def mul(x, y):
            return x * y

        def dfs(x, f, con, prime, r):
            v = [1 - prime[x], prime[x]]
            for y in con[x]:
                if y == f:
                    continue
                p = dfs(y, x, con, prime, r)
                r[0] += mul(p[0], v[1]) + mul(p[1], v[0])
                if prime[x]:
                    v[1] += p[0]
                else:
                    v[0] += p[0]
                    v[1] += p[1]
            return v

        prime = [True] * (n + 1)
        prime[1] = False

        all_primes = []
        for i in range(2, n + 1):
            if prime[i]:
                all_primes.append(i)
            for x in all_primes:
                temp = i * x
                if temp > n:
                    break
                prime[temp] = False
                if i % x == 0:
                    break

        con = [[] for _ in range(n + 1)]
        for e in edges:
            con[e[0]].append(e[1])
            con[e[1]].append(e[0])

        r = [0]
        dfs(1, 0, con, prime, r)
        return r[0]
```

#### Java

```java
class Solution {
    public long countPaths(int n, int[][] edges) {
        List<Boolean> prime = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; ++i) {
            prime.add(true);
        }
        prime.set(1, false);

        List<Integer> all = new ArrayList<>();
        for (int i = 2; i <= n; ++i) {
            if (prime.get(i)) {
                all.add(i);
            }
            for (int x : all) {
                int temp = i * x;
                if (temp > n) {
                    break;
                }
                prime.set(temp, false);
                if (i % x == 0) {
                    break;
                }
            }
        }

        List<List<Integer>> con = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; ++i) {
            con.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            con.get(e[0]).add(e[1]);
            con.get(e[1]).add(e[0]);
        }

        long[] r = {0};
        dfs(1, 0, con, prime, r);
        return r[0];
    }

    private long mul(long x, long y) {
        return x * y;
    }

    private class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    private Pair dfs(int x, int f, List<List<Integer>> con, List<Boolean> prime, long[] r) {
        Pair v = new Pair(!prime.get(x) ? 1 : 0, prime.get(x) ? 1 : 0);
        for (int y : con.get(x)) {
            if (y == f) continue;
            Pair p = dfs(y, x, con, prime, r);
            r[0] += mul(p.first, v.second) + mul(p.second, v.first);
            if (prime.get(x)) {
                v.second += p.first;
            } else {
                v.first += p.first;
                v.second += p.second;
            }
        }
        return v;
    }
}
```

#### C++

```cpp
class Solution {
    long long mul(long long x, long long y) {
        return x * y;
    }

    pair<int, int> dfs(int x, int f, const vector<vector<int>>& con, const vector<bool>& prime, long long& r) {
        pair<int, int> v = {!prime[x], prime[x]};
        for (int y : con[x]) {
            if (y == f) continue;
            const auto& p = dfs(y, x, con, prime, r);
            r += mul(p.first, v.second) + mul(p.second, v.first);
            if (prime[x]) {
                v.second += p.first;
            } else {
                v.first += p.first;
                v.second += p.second;
            }
        }
        return v;
    }

public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> prime(n + 1, true);
        prime[1] = false;
        vector<int> all;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                all.push_back(i);
            }
            for (int x : all) {
                const int temp = i * x;
                if (temp > n) {
                    break;
                }
                prime[temp] = false;
                if (i % x == 0) {
                    break;
                }
            }
        }
        vector<vector<int>> con(n + 1);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        long long r = 0;
        dfs(1, 0, con, prime, r);
        return r;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2868. 单词游戏 🔒](https://leetcode.cn/problems/the-wording-game){#2868}

{{< tabs "2868" >}}

{{% tab "python" %}}
```python
class Solution:
    def canAliceWin(self, a: List[str], b: List[str]) -> bool:
        i, j, k = 1, 0, 1
        w = a[0]
        while 1:
            if k:
                if j == len(b):
                    return True
                if (b[j][0] == w[0] and b[j] > w) or ord(b[j][0]) - ord(w[0]) == 1:
                    w = b[j]
                    k ^= 1
                j += 1
            else:
                if i == len(a):
                    return False
                if (a[i][0] == w[0] and a[i] > w) or ord(a[i][0]) - ord(w[0]) == 1:
                    w = a[i]
                    k ^= 1
                i += 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canAliceWin(String[] a, String[] b) {
        int i = 1, j = 0;
        boolean k = true;
        String w = a[0];
        while (true) {
            if (k) {
                if (j == b.length) {
                    return true;
                }
                if ((b[j].charAt(0) == w.charAt(0) && w.compareTo(b[j]) < 0)
                    || b[j].charAt(0) - w.charAt(0) == 1) {
                    w = b[j];
                    k = !k;
                }
                ++j;
            } else {
                if (i == a.length) {
                    return false;
                }
                if ((a[i].charAt(0) == w.charAt(0) && w.compareTo(a[i]) < 0)
                    || a[i].charAt(0) - w.charAt(0) == 1) {
                    w = a[i];
                    k = !k;
                }
                ++i;
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
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        int i = 1, j = 0, k = 1;
        string w = a[0];
        while (1) {
            if (k) {
                if (j == b.size()) {
                    return true;
                }
                if ((b[j][0] == w[0] && w < b[j]) || b[j][0] - w[0] == 1) {
                    w = b[j];
                    k ^= 1;
                }
                ++j;
            } else {
                if (i == a.size()) {
                    return false;
                }
                if ((a[i][0] == w[0] && w < a[i]) || a[i][0] - w[0] == 1) {
                    w = a[i];
                    k ^= 1;
                }
                ++i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canAliceWin(a []string, b []string) bool {
	i, j, k := 1, 0, 1
	w := a[0]
	for {
		if k&1 == 1 {
			if j == len(b) {
				return true
			}
			if (b[j][0] == w[0] && w < b[j]) || b[j][0]-w[0] == 1 {
				w = b[j]
				k ^= 1
			}
			j++
		} else {
			if i == len(a) {
				return false
			}
			if (a[i][0] == w[0] && w < a[i]) || a[i][0]-w[0] == 1 {
				w = a[i]
				k ^= 1
			}
			i++
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canAliceWin(a: string[], b: string[]): boolean {
    let [i, j, k] = [1, 0, 1];
    let w = a[0];
    while (1) {
        if (k) {
            if (j === b.length) {
                return true;
            }
            if ((b[j][0] === w[0] && w < b[j]) || b[j].charCodeAt(0) - w.charCodeAt(0) === 1) {
                w = b[j];
                k ^= 1;
            }
            ++j;
        } else {
            if (i === a.length) {
                return false;
            }
            if ((a[i][0] === w[0] && w < a[i]) || a[i].charCodeAt(0) - w.charCodeAt(0) === 1) {
                w = a[i];
                k ^= 1;
            }
            ++i;
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

<p>Alice 和 Bob 分别拥有一个&nbsp;<strong>按字典序排序&nbsp;</strong>的字符串数组，分别命名为 <code>a</code>&nbsp;和 <code>b</code>。</p>

<p>他们正在玩一个单词游戏，遵循以下规则：</p>

<ul>
	<li>每一轮，当前玩家应该从他的列表中选择一个单词，并且选择的单词比上一个单词 <strong>紧邻大</strong>；然后轮到另一名玩家。</li>
	<li>如果一名玩家在自己的回合中无法选择单词，则输掉比赛。</li>
</ul>

<p>Alice 通过选择在 <strong>字典序最小</strong> 的单词开始游戏。</p>

<p>给定 <code>a</code> 和 <code>b</code>，已知两名玩家都按最佳策略玩游戏，如果 Alice 可以获胜，则返回 <code>true</code>&nbsp;，否则返回 <code>false</code>。</p>

<p>如果满足以下条件，则称一个单词 <code>w</code>&nbsp;比另一个单词 <code>z</code>&nbsp;<strong>紧邻大</strong>：</p>

<ul>
	<li><code>w</code> 在&nbsp;<strong>字典序上大于</strong> <code>z</code>。</li>
	<li>如果 <code>w<sub>1</sub></code> 是 <code>w</code> 的第一个字母，<code>z<sub>1</sub></code> 是 <code>z</code> 的第一个字母，那么 <code>w<sub>1</sub></code> 应该 <strong>等于</strong> <code>z<sub>1</sub></code> 或者是字母表中 <code>z<sub>1</sub></code> <strong>后面相邻&nbsp;</strong>的字母。</li>
	<li>例如，单词 <code>"care"</code>&nbsp;比&nbsp;<code>"book"</code> 和 <code>"car"</code>&nbsp;紧邻大，但不比&nbsp;<code>"ant"</code> 或 <code>"cook"</code>&nbsp;紧邻大。</li>
</ul>

<p>如果在 <code>s</code> 和 <code>t</code> 不同的第一个位置处，字符串 <code>s</code>&nbsp;的字母比字符串 <code>t</code>&nbsp;的字母在字母表中的顺序更靠后，则称为字符串 <code>s</code> 在 <strong>字典序上大于</strong> 字符串 <code>t</code>。如果前 <code>min(s.length, t.length)</code> 个字符没有区别，那么较长的字符串是在字典序上较大的那一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> a = ["avokado","dabar"], b = ["brazil"]

<strong>输出:</strong> false

<strong>解释:</strong> Alice 必须从单词 "avokado" 来开始游戏，因为这是她最小的单词，然后 Bob 使用他唯一的单词 "brazil"，他可以使用它因为它的第一个字母 'b' 在 Alice 的单词的第一个字母 'a' 之后。

Alice 无法出牌，因为剩下的唯一单词的第一个字母既不等于 'b' 也不是 'b' 之后的字母 'c'。

所以，Alice 输了，游戏结束。</pre>

<strong>示例 2：</strong>

<pre>
<strong>输入:</strong> a = ["ananas","atlas","banana"], b = ["albatros","cikla","nogomet"]

<strong>输出:</strong> true

<strong>解释:</strong> Alice 必须从单词 "ananas" 来开始游戏。

Bob 无法出牌，因为他唯一拥有的以字母 'a' 或 'b' 开头的单词是 "albatros"，而它比 Alice 的单词小。

所以，Alice 获胜，游戏结束。</pre>

<strong>示例 3：</strong>

<pre>
<strong>输入:</strong> a = ["hrvatska","zastava"], b = ["bijeli","galeb"]

<strong>输出:</strong> true

<strong>解释:</strong> Alice 必须从单词 "hrvatska" 来开始游戏。

Bob 无法出牌，因为他的两个单词的第一个字母都比 Alice 的单词的第一个字母 'h' 小。

所以，Alice 获胜，游戏结束。</pre>

<p>&nbsp;</p>

<p><strong>约束条件：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a[i]</code> 和 <code>b[i]</code> 仅包含小写英文字母。</li>
	<li><code>a</code> 和 <code>b</code> 按 <strong>字典序排序</strong>。</li>
	<li><code>a</code> 和 <code>b</code> 中所有的单词都是&nbsp;<strong>不同的</strong>。</li>
	<li><code>a</code> 和 <code>b</code> 中所有单词的长度之和不超过 <code>10<sup>6</sup></code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们记当前轮到 $Alice$ 的回合为 $k=0$，轮到 $Bob$ 的回合为 $k=1$。我们用 $i$ 记录 $Alice$ 的下标，用 $j$ 记录 $Bob$ 的下标，用 $w$ 记录当前轮到的玩家的单词。初始时 $i=1$, $j=0$, $w=a[0]$。

我们不断地进行如下操作：

如果 $k=1$，则我们判断 $j$ 是否等于 $b$ 的长度，如果等于则说明 $Alice$ 获胜，返回 $true$；否则我们判断 $b[j]$ 的第一个字母是否等于 $w$ 的第一个字母，如果等于则我们判断 $b[j]$ 是否大于 $w$，或者 $b[j]$ 的第一个字母是否比 $w$ 的第一个字母大 $1$，如果是则说明 $Bob$ 可以出第 $j$ 个单词，我们令 $w=b[j]$，并将 $k$ 取反；否则说明 $Bob$ 无法出第 $j$ 个单词，我们令 $j$ 加一。

如果 $k=0$，则我们判断 $i$ 是否等于 $a$ 的长度，如果等于则说明 $Bob$ 获胜，返回 $false$；否则我们判断 $a[i]$ 的第一个字母是否等于 $w$ 的第一个字母，如果等于则我们判断 $a[i]$ 是否大于 $w$，或者 $a[i]$ 的第一个字母是否比 $w$ 的第一个字母大 $1$，如果是则说明 $Alice$ 可以出第 $i$ 个单词，我们令 $w=a[i]$，并将 $k$ 取反；否则说明 $Alice$ 无法出第 $i$ 个单词，我们令 $i$ 加一。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是数组 $a$ 和 $b$ 的长度。我们只需要遍历数组一次。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canAliceWin(self, a: List[str], b: List[str]) -> bool:
        i, j, k = 1, 0, 1
        w = a[0]
        while 1:
            if k:
                if j == len(b):
                    return True
                if (b[j][0] == w[0] and b[j] > w) or ord(b[j][0]) - ord(w[0]) == 1:
                    w = b[j]
                    k ^= 1
                j += 1
            else:
                if i == len(a):
                    return False
                if (a[i][0] == w[0] and a[i] > w) or ord(a[i][0]) - ord(w[0]) == 1:
                    w = a[i]
                    k ^= 1
                i += 1
```

#### Java

```java
class Solution {
    public boolean canAliceWin(String[] a, String[] b) {
        int i = 1, j = 0;
        boolean k = true;
        String w = a[0];
        while (true) {
            if (k) {
                if (j == b.length) {
                    return true;
                }
                if ((b[j].charAt(0) == w.charAt(0) && w.compareTo(b[j]) < 0)
                    || b[j].charAt(0) - w.charAt(0) == 1) {
                    w = b[j];
                    k = !k;
                }
                ++j;
            } else {
                if (i == a.length) {
                    return false;
                }
                if ((a[i].charAt(0) == w.charAt(0) && w.compareTo(a[i]) < 0)
                    || a[i].charAt(0) - w.charAt(0) == 1) {
                    w = a[i];
                    k = !k;
                }
                ++i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        int i = 1, j = 0, k = 1;
        string w = a[0];
        while (1) {
            if (k) {
                if (j == b.size()) {
                    return true;
                }
                if ((b[j][0] == w[0] && w < b[j]) || b[j][0] - w[0] == 1) {
                    w = b[j];
                    k ^= 1;
                }
                ++j;
            } else {
                if (i == a.size()) {
                    return false;
                }
                if ((a[i][0] == w[0] && w < a[i]) || a[i][0] - w[0] == 1) {
                    w = a[i];
                    k ^= 1;
                }
                ++i;
            }
        }
    }
};
```

#### Go

```go
func canAliceWin(a []string, b []string) bool {
	i, j, k := 1, 0, 1
	w := a[0]
	for {
		if k&1 == 1 {
			if j == len(b) {
				return true
			}
			if (b[j][0] == w[0] && w < b[j]) || b[j][0]-w[0] == 1 {
				w = b[j]
				k ^= 1
			}
			j++
		} else {
			if i == len(a) {
				return false
			}
			if (a[i][0] == w[0] && w < a[i]) || a[i][0]-w[0] == 1 {
				w = a[i]
				k ^= 1
			}
			i++
		}
	}
}
```

#### TypeScript

```ts
function canAliceWin(a: string[], b: string[]): boolean {
    let [i, j, k] = [1, 0, 1];
    let w = a[0];
    while (1) {
        if (k) {
            if (j === b.length) {
                return true;
            }
            if ((b[j][0] === w[0] && w < b[j]) || b[j].charCodeAt(0) - w.charCodeAt(0) === 1) {
                w = b[j];
                k ^= 1;
            }
            ++j;
        } else {
            if (i === a.length) {
                return false;
            }
            if ((a[i][0] === w[0] && w < a[i]) || a[i].charCodeAt(0) - w.charCodeAt(0) === 1) {
                w = a[i];
                k ^= 1;
            }
            ++i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2869. 收集元素的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-collect-elements){#2869}

{{< tabs "2869" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        is_added = [False] * k
        count = 0
        n = len(nums)
        for i in range(n - 1, -1, -1):
            if nums[i] > k or is_added[nums[i] - 1]:
                continue
            is_added[nums[i] - 1] = True
            count += 1
            if count == k:
                return n - i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(List<Integer> nums, int k) {
        boolean[] isAdded = new boolean[k];
        int n = nums.size();
        int count = 0;
        for (int i = n - 1;; i--) {
            if (nums.get(i) > k || isAdded[nums.get(i) - 1]) {
                continue;
            }
            isAdded[nums.get(i) - 1] = true;
            count++;
            if (count == k) {
                return n - i;
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
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isAdded(n);
        int count = 0;
        for (int i = n - 1;; --i) {
            if (nums[i] > k || isAdded[nums[i] - 1]) {
                continue;
            }
            isAdded[nums[i] - 1] = true;
            if (++count == k) {
                return n - i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, k int) int {
	isAdded := make([]bool, k)
	count := 0
	n := len(nums)
	for i := n - 1; ; i-- {
		if nums[i] > k || isAdded[nums[i]-1] {
			continue
		}
		isAdded[nums[i]-1] = true
		count++
		if count == k {
			return n - i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], k: number): number {
    const n = nums.length;
    const isAdded = Array(k).fill(false);
    let count = 0;
    for (let i = n - 1; ; --i) {
        if (nums[i] > k || isAdded[nums[i] - 1]) {
            continue;
        }
        isAdded[nums[i] - 1] = true;
        ++count;
        if (count === k) {
            return n - i;
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

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一次操作中，你可以将数组的最后一个元素删除，将该元素添加到一个集合中。</p>

<p>请你返回收集元素&nbsp;<code>1, 2, ..., k</code>&nbsp;需要的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,1,5,4,2], k = 2
<b>输出：</b>4
<b>解释：</b>4 次操作后，集合中的元素依次添加了 2 ，4 ，5 和 1 。此时集合中包含元素 1 和 2 ，所以答案为 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,1,5,4,2], k = 5
<b>输出：</b>5
<b>解释：</b>5 次操作后，集合中的元素依次添加了 2 ，4 ，5 ，1 和 3 。此时集合中包含元素 1 到 5 ，所以答案为 5 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,5,3,1], k = 3
<b>输出：</b>4
<b>解释：</b>4 次操作后，集合中的元素依次添加了 1 ，3 ，5 和 2 。此时集合中包含元素 1 到 3  ，所以答案为 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
	<li>输入保证你可以收集到元素&nbsp;<code>1, 2, ..., k</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆序遍历

我们可以逆序遍历数组，每次遍历到的元素如果小于等于 $k$，且没有被添加过，就将其添加到集合中，直到集合中包含了元素 $1$ 到 $k$ 为止。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        is_added = [False] * k
        count = 0
        n = len(nums)
        for i in range(n - 1, -1, -1):
            if nums[i] > k or is_added[nums[i] - 1]:
                continue
            is_added[nums[i] - 1] = True
            count += 1
            if count == k:
                return n - i
```

#### Java

```java
class Solution {
    public int minOperations(List<Integer> nums, int k) {
        boolean[] isAdded = new boolean[k];
        int n = nums.size();
        int count = 0;
        for (int i = n - 1;; i--) {
            if (nums.get(i) > k || isAdded[nums.get(i) - 1]) {
                continue;
            }
            isAdded[nums.get(i) - 1] = true;
            count++;
            if (count == k) {
                return n - i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isAdded(n);
        int count = 0;
        for (int i = n - 1;; --i) {
            if (nums[i] > k || isAdded[nums[i] - 1]) {
                continue;
            }
            isAdded[nums[i] - 1] = true;
            if (++count == k) {
                return n - i;
            }
        }
    }
};
```

#### Go

```go
func minOperations(nums []int, k int) int {
	isAdded := make([]bool, k)
	count := 0
	n := len(nums)
	for i := n - 1; ; i-- {
		if nums[i] > k || isAdded[nums[i]-1] {
			continue
		}
		isAdded[nums[i]-1] = true
		count++
		if count == k {
			return n - i
		}
	}
}
```

#### TypeScript

```ts
function minOperations(nums: number[], k: number): number {
    const n = nums.length;
    const isAdded = Array(k).fill(false);
    let count = 0;
    for (let i = n - 1; ; --i) {
        if (nums[i] > k || isAdded[nums[i] - 1]) {
            continue;
        }
        isAdded[nums[i] - 1] = true;
        ++count;
        if (count === k) {
            return n - i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
