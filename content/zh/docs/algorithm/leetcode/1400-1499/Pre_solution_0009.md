---
title: "1480_一维数组的动态和"
date: 2025-10-08T18:37:18+08:00
weight: 9
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 强连通分量, 排序, 数学, 数据库, 数组, 最小生成树, 树, 深度优先搜索, 计数, 设计, 贪心]
---

{{< markmap >}}
### [1480_一维数组的动态和](#1480)
#### [数组](#1480)
#### [前缀和](#1480)
### [1481_不同整数的最少数目](#1481)
#### [贪心](#1481)
#### [数组](#1481)
#### [哈希表](#1481)
#### [计数](#1481)
#### [排序](#1481)
### [1482_制作 m 束花所需的最少天数](#1482)
#### [数组](#1482)
#### [二分查找](#1482)
### [1483_树节点的第 K 个祖先](#1483)
#### [树](#1483)
#### [深度优先搜索](#1483)
#### [广度优先搜索](#1483)
#### [设计](#1483)
#### [二分查找](#1483)
#### [动态规划](#1483)
### [1484_按日期分组销售产品](#1484)
#### [数据库](#1484)
### [1485_克隆含随机指针的二叉树 🔒](#1485)
#### [树](#1485)
#### [深度优先搜索](#1485)
#### [广度优先搜索](#1485)
#### [哈希表](#1485)
#### [二叉树](#1485)
### [1486_数组异或操作](#1486)
#### [位运算](#1486)
#### [数学](#1486)
### [1487_保证文件名唯一](#1487)
#### [数组](#1487)
#### [哈希表](#1487)
#### [字符串](#1487)
### [1488_避免洪水泛滥](#1488)
#### [贪心](#1488)
#### [数组](#1488)
#### [哈希表](#1488)
#### [二分查找](#1488)
#### [堆（优先队列）](#1488)
### [1489_找到最小生成树里的关键边和伪关键边](#1489)
#### [并查集](#1489)
#### [图](#1489)
#### [最小生成树](#1489)
#### [排序](#1489)
#### [强连通分量](#1489)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1480_一维数组的动态和
___
#### 数组
___
#### 前缀和
---
### 1481_不同整数的最少数目
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
---
### 1482_制作 m 束花所需的最少天数
___
#### 数组
___
#### 二分查找
---
### 1483_树节点的第 K 个祖先
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 二分查找
___
#### 动态规划
---
### 1484_按日期分组销售产品
___
#### 数据库
---
### 1485_克隆含随机指针的二叉树 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 1486_数组异或操作
___
#### 位运算
___
#### 数学
---
### 1487_保证文件名唯一
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1488_避免洪水泛滥
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 堆（优先队列）
---
### 1489_找到最小生成树里的关键边和伪关键边
___
#### 并查集
___
#### 图
___
#### 最小生成树
___
#### 排序
___
#### 强连通分量
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 并查集 | 广度优先搜索 | 强连通分量 |
| 排序 | 数学 | 数据库 |
| 数组 | 最小生成树 | 树 |
| 深度优先搜索 | 计数 | 设计 |
| 贪心 |  |  |

# [1480. 一维数组的动态和](https://leetcode.cn/problems/running-sum-of-1d-array){#1480}

{{< tabs "1480" >}}

{{% tab "python" %}}
```python
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return list(accumulate(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func runningSum(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function runningSum(nums: number[]): number[] {
    for (let i = 1; i < nums.length; ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] RunningSum(int[] nums) {
        for (int i = 1; i < nums.Length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function runningSum($nums) {
        for ($i = 1; $i < count($nums); $i++) {
            $nums[$i] += $nums[$i - 1];
        }
        return $nums;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> 。数组「动态和」的计算公式为：<code>runningSum[i] = sum(nums[0]&hellip;nums[i])</code> 。</p>

<p>请返回 <code>nums</code> 的动态和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[1,3,6,10]
<strong>解释：</strong>动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1,1]
<strong>输出：</strong>[1,2,3,4,5]
<strong>解释：</strong>动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,1,2,10,1]
<strong>输出：</strong>[3,4,6,16,17]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10^6&nbsp;&lt;= nums[i] &lt;=&nbsp;10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们直接遍历数组，对于当前元素 $nums[i]$，我们将其与前缀和 $nums[i-1]$ 相加，即可得到当前元素的前缀和 $nums[i]$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return list(accumulate(nums))
```

#### Java

```java
class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};
```

#### Go

```go
func runningSum(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return nums
}
```

#### TypeScript

```ts
function runningSum(nums: number[]): number[] {
    for (let i = 1; i < nums.length; ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}
```

#### C#

```cs
public class Solution {
    public int[] RunningSum(int[] nums) {
        for (int i = 1; i < nums.Length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function runningSum($nums) {
        for ($i = 1; $i < count($nums); $i++) {
            $nums[$i] += $nums[$i - 1];
        }
        return $nums;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1481. 不同整数的最少数目](https://leetcode.cn/problems/least-number-of-unique-integers-after-k-removals){#1481}

{{< tabs "1481" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnt = Counter(arr)
        for i, v in enumerate(sorted(cnt.values())):
            k -= v
            if k < 0:
                return len(cnt) - i
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) {
            cnt.merge(x, 1, Integer::sum);
        }
        List<Integer> nums = new ArrayList<>(cnt.values());
        Collections.sort(nums);
        for (int i = 0, m = nums.size(); i < m; ++i) {
            k -= nums.get(i);
            if (k < 0) {
                return m - i;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        vector<int> nums;
        for (auto& [_, c] : cnt) {
            nums.push_back(c);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0, m = nums.size(); i < m; ++i) {
            k -= nums[i];
            if (k < 0) {
                return m - i;
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLeastNumOfUniqueInts(arr []int, k int) int {
	cnt := map[int]int{}
	for _, x := range arr {
		cnt[x]++
	}
	nums := make([]int, 0, len(cnt))
	for _, v := range cnt {
		nums = append(nums, v)
	}
	sort.Ints(nums)
	for i, v := range nums {
		k -= v
		if k < 0 {
			return len(nums) - i
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLeastNumOfUniqueInts(arr: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of arr) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    const nums = [...cnt.values()].sort((a, b) => a - b);

    for (let i = 0; i < nums.length; ++i) {
        k -= nums[i];
        if (k < 0) {
            return nums.length - i;
        }
    }
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> 。现需要从数组中恰好移除 <code>k</code> 个元素，请找出移除后数组中不同整数的最少数目。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>移除 1 个 4 ，数组中只剩下 5 一种整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,1,1,3,3,2], k = 3
<strong>输出：</strong>2
<strong>解释：</strong>先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们用哈希表 $cnt$ 统计数组 $arr$ 中每个整数出现的次数，然后将 $cnt$ 中的值按照从小到大的顺序排序，记录在数组 $nums$ 中。

接下来，我们遍历数组 $nums$，对于当前遍历到的每个值 $nums[i]$，我们将 $k$ 减去 $nums[i]$，如果 $k \lt 0$，则说明我们已经移除了 $k$ 个元素，此时数组中不同整数的最少数目为 $nums$ 的长度减去当前遍历到的下标 $i$，直接返回即可。

若遍历结束，说明我们移除了所有的元素，此时数组中不同整数的最少数目为 $0$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnt = Counter(arr)
        for i, v in enumerate(sorted(cnt.values())):
            k -= v
            if k < 0:
                return len(cnt) - i
        return 0
```

#### Java

```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) {
            cnt.merge(x, 1, Integer::sum);
        }
        List<Integer> nums = new ArrayList<>(cnt.values());
        Collections.sort(nums);
        for (int i = 0, m = nums.size(); i < m; ++i) {
            k -= nums.get(i);
            if (k < 0) {
                return m - i;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        vector<int> nums;
        for (auto& [_, c] : cnt) {
            nums.push_back(c);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0, m = nums.size(); i < m; ++i) {
            k -= nums[i];
            if (k < 0) {
                return m - i;
            }
        }
        return 0;
    }
};
```

#### Go

```go
func findLeastNumOfUniqueInts(arr []int, k int) int {
	cnt := map[int]int{}
	for _, x := range arr {
		cnt[x]++
	}
	nums := make([]int, 0, len(cnt))
	for _, v := range cnt {
		nums = append(nums, v)
	}
	sort.Ints(nums)
	for i, v := range nums {
		k -= v
		if k < 0 {
			return len(nums) - i
		}
	}
	return 0
}
```

#### TypeScript

```ts
function findLeastNumOfUniqueInts(arr: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of arr) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    const nums = [...cnt.values()].sort((a, b) => a - b);

    for (let i = 0; i < nums.length; ++i) {
        k -= nums[i];
        if (k < 0) {
            return nums.length - i;
        }
    }
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1482. 制作 m 束花所需的最少天数](https://leetcode.cn/problems/minimum-number-of-days-to-make-m-bouquets){#1482}

{{< tabs "1482" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def check(days: int) -> int:
            cnt = cur = 0
            for x in bloomDay:
                cur = cur + 1 if x <= days else 0
                if cur == k:
                    cnt += 1
                    cur = 0
            return cnt >= m

        mx = max(bloomDay)
        l = bisect_left(range(mx + 2), True, key=check)
        return -1 if l > mx else l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] bloomDay;
    private int m, k;

    public int minDays(int[] bloomDay, int m, int k) {
        this.bloomDay = bloomDay;
        this.m = m;
        this.k = k;
        final int mx = (int) 1e9;
        int l = 1, r = mx + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > mx ? -1 : l;
    }

    private boolean check(int days) {
        int cnt = 0, cur = 0;
        for (int x : bloomDay) {
            cur = x <= days ? cur + 1 : 0;
            if (cur == k) {
                ++cnt;
                cur = 0;
            }
        }
        return cnt >= m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = ranges::max(bloomDay);
        int l = 1, r = mx + 1;
        auto check = [&](int days) {
            int cnt = 0, cur = 0;
            for (int x : bloomDay) {
                cur = x <= days ? cur + 1 : 0;
                if (cur == k) {
                    cnt++;
                    cur = 0;
                }
            }
            return cnt >= m;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > mx ? -1 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDays(bloomDay []int, m int, k int) int {
	mx := slices.Max(bloomDay)
	if l := sort.Search(mx+2, func(days int) bool {
		cnt, cur := 0, 0
		for _, x := range bloomDay {
			if x <= days {
				cur++
				if cur == k {
					cnt++
					cur = 0
				}
			} else {
				cur = 0
			}
		}
		return cnt >= m
	}); l <= mx {
		return l
	}
	return -1

}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDays(bloomDay: number[], m: number, k: number): number {
    const mx = Math.max(...bloomDay);
    let [l, r] = [1, mx + 1];
    const check = (days: number): boolean => {
        let [cnt, cur] = [0, 0];
        for (const x of bloomDay) {
            cur = x <= days ? cur + 1 : 0;
            if (cur === k) {
                cnt++;
                cur = 0;
            }
        }
        return cnt >= m;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > mx ? -1 : l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>bloomDay</code>，以及两个整数 <code>m</code> 和 <code>k</code> 。</p>

<p>现需要制作 <code>m</code> 束花。制作花束时，需要使用花园中 <strong>相邻的 <code>k</code> 朵花</strong> 。</p>

<p>花园中有 <code>n</code> 朵花，第 <code>i</code> 朵花会在 <code>bloomDay[i]</code> 时盛开，<strong>恰好</strong> 可以用于 <strong>一束</strong> 花中。</p>

<p>请你返回从花园中摘 <code>m</code> 束花需要等待的最少的天数。如果不能摘到 <code>m</code> 束花则返回 <strong>-1</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>bloomDay = [1,10,3,10,2], m = 3, k = 1
<strong>输出：</strong>3
<strong>解释：</strong>让我们一起观察这三天的花开过程，x 表示花开，而 _ 表示花还未开。
现在需要制作 3 束花，每束只需要 1 朵。
1 天后：[x, _, _, _, _]   // 只能制作 1 束花
2 天后：[x, _, _, _, x]   // 只能制作 2 束花
3 天后：[x, _, x, _, x]   // 可以制作 3 束花，答案为 3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>bloomDay = [1,10,3,10,2], m = 3, k = 2
<strong>输出：</strong>-1
<strong>解释：</strong>要制作 3 束花，每束需要 2 朵花，也就是一共需要 6 朵花。而花园中只有 5 朵花，无法满足制作要求，返回 -1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
<strong>输出：</strong>12
<strong>解释：</strong>要制作 2 束花，每束需要 3 朵。
花园在 7 天后和 12 天后的情况如下：
7 天后：[x, x, x, x, _, x, x]
可以用前 3 朵盛开的花制作第一束花。但不能使用后 3 朵盛开的花，因为它们不相邻。
12 天后：[x, x, x, x, x, x, x]
显然，我们可以用不同的方式制作两束花。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>bloomDay = [1000000000,1000000000], m = 1, k = 1
<strong>输出：</strong>1000000000
<strong>解释：</strong>需要等 1000000000 天才能采到花来制作花束
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>bloomDay.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= bloomDay[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= m &lt;= 10^6</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

根据题目描述，如果一个天数 $t$ 可以满足制作 $m$ 束花，那么对任意 $t' > t$，也一定可以满足制作 $m$ 束花。因此，我们可以使用二分查找的方法找到最小的满足制作 $m$ 束花的天数。

我们记花园中最大的开花天数为 $mx$，接下来，我们定义二分查找的左边界 $l = 1$，右边界 $r = mx + 1$。

然后，我们进行二分查找，对于每一个中间值 $\textit{mid} = \frac{l + r}{2}$，我们判断是否可以制作 $m$ 束花。如果可以，我们将右边界 $r$ 更新为 $\textit{mid}$，否则，我们将左边界 $l$ 更新为 $\textit{mid} + 1$。

最终，当 $l = r$ 时，结束二分查找。此时如果 $l > mx$，说明无法制作 $m$ 束花，返回 $-1$，否则返回 $l$。

因此，问题转换为判断一个天数 $\textit{days}$ 是否可以制作 $m$ 束花。

我们可以使用一个函数 $\text{check}(\textit{days})$ 来判断是否可以制作 $m$ 束花。具体地，我们从左到右遍历花园中的每一朵花，如果当前花开的天数小于等于 $\textit{days}$，我们将当前花加入到当前花束中，否则，我们将当前花束清空。当当前花束中的花的数量等于 $k$ 时，我们将当前花束的数量加一，并清空当前花束。最后，我们判断当前花束的数量是否大于等于 $m$，如果是，说明可以制作 $m$ 束花，否则，说明无法制作 $m$ 束花。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别为花园中的花的数量和最大的开花天数，本题中 $M \leq 10^9$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def check(days: int) -> int:
            cnt = cur = 0
            for x in bloomDay:
                cur = cur + 1 if x <= days else 0
                if cur == k:
                    cnt += 1
                    cur = 0
            return cnt >= m

        mx = max(bloomDay)
        l = bisect_left(range(mx + 2), True, key=check)
        return -1 if l > mx else l
```

#### Java

```java
class Solution {
    private int[] bloomDay;
    private int m, k;

    public int minDays(int[] bloomDay, int m, int k) {
        this.bloomDay = bloomDay;
        this.m = m;
        this.k = k;
        final int mx = (int) 1e9;
        int l = 1, r = mx + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > mx ? -1 : l;
    }

    private boolean check(int days) {
        int cnt = 0, cur = 0;
        for (int x : bloomDay) {
            cur = x <= days ? cur + 1 : 0;
            if (cur == k) {
                ++cnt;
                cur = 0;
            }
        }
        return cnt >= m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = ranges::max(bloomDay);
        int l = 1, r = mx + 1;
        auto check = [&](int days) {
            int cnt = 0, cur = 0;
            for (int x : bloomDay) {
                cur = x <= days ? cur + 1 : 0;
                if (cur == k) {
                    cnt++;
                    cur = 0;
                }
            }
            return cnt >= m;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > mx ? -1 : l;
    }
};
```

#### Go

```go
func minDays(bloomDay []int, m int, k int) int {
	mx := slices.Max(bloomDay)
	if l := sort.Search(mx+2, func(days int) bool {
		cnt, cur := 0, 0
		for _, x := range bloomDay {
			if x <= days {
				cur++
				if cur == k {
					cnt++
					cur = 0
				}
			} else {
				cur = 0
			}
		}
		return cnt >= m
	}); l <= mx {
		return l
	}
	return -1

}
```

#### TypeScript

```ts
function minDays(bloomDay: number[], m: number, k: number): number {
    const mx = Math.max(...bloomDay);
    let [l, r] = [1, mx + 1];
    const check = (days: number): boolean => {
        let [cnt, cur] = [0, 0];
        for (const x of bloomDay) {
            cur = x <= days ? cur + 1 : 0;
            if (cur === k) {
                cnt++;
                cur = 0;
            }
        }
        return cnt >= m;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > mx ? -1 : l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1483. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node){#1483}

{{< tabs "1483" >}}

{{% tab "python" %}}
```python
class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.p = [[-1] * 18 for _ in range(n)]
        for i, fa in enumerate(parent):
            self.p[i][0] = fa
        for j in range(1, 18):
            for i in range(n):
                if self.p[i][j - 1] == -1:
                    continue
                self.p[i][j] = self.p[self.p[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(17, -1, -1):
            if k >> i & 1:
                node = self.p[node][i]
                if node == -1:
                    break
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TreeAncestor {
    private int[][] p;

    public TreeAncestor(int n, int[] parent) {
        p = new int[n][18];
        for (var e : p) {
            Arrays.fill(e, -1);
        }
        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        for (int i = 17; i >= 0; --i) {
            if (((k >> i) & 1) == 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.getKthAncestor(node,k);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        p = vector<vector<int>>(n, vector<int>(18, -1));
        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 17; ~i; --i) {
            if (k >> i & 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }

private:
    vector<vector<int>> p;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TreeAncestor struct {
	p [][18]int
}

func Constructor(n int, parent []int) TreeAncestor {
	p := make([][18]int, n)
	for i, fa := range parent {
		p[i][0] = fa
		for j := 1; j < 18; j++ {
			p[i][j] = -1
		}
	}
	for j := 1; j < 18; j++ {
		for i := range p {
			if p[i][j-1] == -1 {
				continue
			}
			p[i][j] = p[p[i][j-1]][j-1]
		}
	}
	return TreeAncestor{p}
}

func (this *TreeAncestor) GetKthAncestor(node int, k int) int {
	for i := 17; i >= 0; i-- {
		if k>>i&1 == 1 {
			node = this.p[node][i]
			if node == -1 {
				break
			}
		}
	}
	return node
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * obj := Constructor(n, parent);
 * param_1 := obj.GetKthAncestor(node,k);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class TreeAncestor {
    private p: number[][];

    constructor(n: number, parent: number[]) {
        const p = new Array(n).fill(0).map(() => new Array(18).fill(-1));
        for (let i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (let j = 1; j < 18; ++j) {
            for (let i = 0; i < n; ++i) {
                if (p[i][j - 1] === -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
        this.p = p;
    }

    getKthAncestor(node: number, k: number): number {
        for (let i = 17; i >= 0; --i) {
            if (((k >> i) & 1) === 1) {
                node = this.p[node][i];
                if (node === -1) {
                    break;
                }
            }
        }
        return node;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * var obj = new TreeAncestor(n, parent)
 * var param_1 = obj.getKthAncestor(node,k)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class TreeAncestor {
    private int[][] p;

    public TreeAncestor(int n, int[] parent) {
        p = new int[n][];
        for (int i = 0; i < n; i++) {
            p[i] = new int[18];
            for (int j = 0; j < 18; j++) {
                p[i][j] = -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }

        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    public int GetKthAncestor(int node, int k) {
        for (int i = 17; i >= 0; --i) {
            if (((k >> i) & 1) == 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }
}


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.GetKthAncestor(node,k);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵树，树上有 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n-1</code> 编号。树以父节点数组的形式给出，其中 <code>parent[i]</code> 是节点 <code>i</code> 的父节点。树的根节点是编号为 <code>0</code> 的节点。</p>

<p>树节点的第 <em><code>k</code> </em>个祖先节点是从该节点到根节点路径上的第 <code>k</code> 个节点。</p>

<p>实现 <code>TreeAncestor</code> 类：</p>

<ul>
	<li><code>TreeAncestor（int n， int[] parent）</code> 对树和父数组中的节点数初始化对象。</li>
	<li><code>getKthAncestor</code><code>(int node, int k)</code> 返回节点 <code>node</code> 的第 <code>k</code> 个祖先节点。如果不存在这样的祖先节点，返回 <code>-1</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1483.Kth%20Ancestor%20of%20a%20Tree%20Node/images/1528_ex1.png" /></strong></p>

<pre>
<strong>输入：</strong>
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

<strong>输出：</strong>
[null,1,0,-1]

<strong>解释：</strong>
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>parent[0] == -1</code> 表示编号为 <code>0</code> 的节点是根节点。</li>
	<li>对于所有的 <code>0 &lt;&nbsp;i &lt; n</code> ，<code>0 &lt;= parent[i] &lt; n</code> 总成立</li>
	<li><code>0 &lt;= node &lt; n</code></li>
	<li>至多查询&nbsp;<code>5 * 10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 倍增

题目要我们寻找节点 $node$ 的第 $k$ 个祖先节点，如果暴力求解，需要从 $node$ 开始向上遍历 $k$ 次，时间复杂度为 $O(k)$，显然会超时。

我们可以使用动态规划，结合倍增的思想来处理。

我们定义 $p[i][j]$ 表示节点 $i$ 的第 $2^j$ 个祖先节点，即 $p[i][j]$ 表示节点 $i$ 向上走 $2^j$ 步的节点。那么我们可以得到状态转移方程：

$$
p[i][j] = p[p[i][j-1]][j-1]
$$

即：要想找到节点 $i$ 的第 $2^j$ 个祖先节点，我们可以先找到节点 $i$ 的第 $2^{j-1}$ 个祖先节点，然后再找到该节点的第 $2^{j-1}$ 个祖先节点即可。所以，我们要找到每个节点的距离为 $2^j$ 的祖先节点，直到达到树的最大高度。

之后对于每次查询，我们可以把 $k$ 拆成二进制的表示形式，然后根据二进制中 $1$ 的位置，累计向上查询，最终得到节点 $node$ 的第 $k$ 个祖先节点。

时间复杂度方面，初始化为 $O(n \times \log n)$，查询为 $O(\log n)$。空间复杂度 $O(n \times \log n)$。其中 $n$ 为树的节点数。

相似题目：

-   [2836. 在传球游戏中最大化函数值](https://github.com/doocs/leetcode/blob/main/solution/2800-2899/2836.Maximize%20Value%20of%20Function%20in%20a%20Ball%20Passing%20Game/README.md)

<!-- tabs:start -->

#### Python3

```python
class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.p = [[-1] * 18 for _ in range(n)]
        for i, fa in enumerate(parent):
            self.p[i][0] = fa
        for j in range(1, 18):
            for i in range(n):
                if self.p[i][j - 1] == -1:
                    continue
                self.p[i][j] = self.p[self.p[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(17, -1, -1):
            if k >> i & 1:
                node = self.p[node][i]
                if node == -1:
                    break
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
```

#### Java

```java
class TreeAncestor {
    private int[][] p;

    public TreeAncestor(int n, int[] parent) {
        p = new int[n][18];
        for (var e : p) {
            Arrays.fill(e, -1);
        }
        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        for (int i = 17; i >= 0; --i) {
            if (((k >> i) & 1) == 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.getKthAncestor(node,k);
 */
```

#### C++

```cpp
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        p = vector<vector<int>>(n, vector<int>(18, -1));
        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 17; ~i; --i) {
            if (k >> i & 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }

private:
    vector<vector<int>> p;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
```

#### Go

```go
type TreeAncestor struct {
	p [][18]int
}

func Constructor(n int, parent []int) TreeAncestor {
	p := make([][18]int, n)
	for i, fa := range parent {
		p[i][0] = fa
		for j := 1; j < 18; j++ {
			p[i][j] = -1
		}
	}
	for j := 1; j < 18; j++ {
		for i := range p {
			if p[i][j-1] == -1 {
				continue
			}
			p[i][j] = p[p[i][j-1]][j-1]
		}
	}
	return TreeAncestor{p}
}

func (this *TreeAncestor) GetKthAncestor(node int, k int) int {
	for i := 17; i >= 0; i-- {
		if k>>i&1 == 1 {
			node = this.p[node][i]
			if node == -1 {
				break
			}
		}
	}
	return node
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * obj := Constructor(n, parent);
 * param_1 := obj.GetKthAncestor(node,k);
 */
```

#### TypeScript

```ts
class TreeAncestor {
    private p: number[][];

    constructor(n: number, parent: number[]) {
        const p = new Array(n).fill(0).map(() => new Array(18).fill(-1));
        for (let i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }
        for (let j = 1; j < 18; ++j) {
            for (let i = 0; i < n; ++i) {
                if (p[i][j - 1] === -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
        this.p = p;
    }

    getKthAncestor(node: number, k: number): number {
        for (let i = 17; i >= 0; --i) {
            if (((k >> i) & 1) === 1) {
                node = this.p[node][i];
                if (node === -1) {
                    break;
                }
            }
        }
        return node;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * var obj = new TreeAncestor(n, parent)
 * var param_1 = obj.getKthAncestor(node,k)
 */
```

#### C#

```cs
public class TreeAncestor {
    private int[][] p;

    public TreeAncestor(int n, int[] parent) {
        p = new int[n][];
        for (int i = 0; i < n; i++) {
            p[i] = new int[18];
            for (int j = 0; j < 18; j++) {
                p[i][j] = -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            p[i][0] = parent[i];
        }

        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                if (p[i][j - 1] == -1) {
                    continue;
                }
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    public int GetKthAncestor(int node, int k) {
        for (int i = 17; i >= 0; --i) {
            if (((k >> i) & 1) == 1) {
                node = p[node][i];
                if (node == -1) {
                    break;
                }
            }
        }
        return node;
    }
}


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.GetKthAncestor(node,k);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1484. 按日期分组销售产品](https://leetcode.cn/problems/group-sold-products-by-the-date){#1484}

{{< tabs "1484" >}}

{{% tab "sql" %}}
```sql
SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表&nbsp;<code>Activities</code>：</p>

<pre>
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
该表没有主键(具有唯一值的列)。它可能包含重复项。
此表的每一行都包含产品名称和在市场上销售的日期。
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出每个日期、销售的不同产品的数量及其名称。<br />
每个日期的销售产品名称应按词典序排列。<br />
返回按&nbsp;<code>sell_date</code> 排序的结果表。<br />
结果表结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Activities</code> 表：
+------------+-------------+
| sell_date  | product     |
+------------+-------------+
| 2020-05-30 | Headphone   |
| 2020-06-01 | Pencil      |
| 2020-06-02 | Mask        |
| 2020-05-30 | Basketball  |
| 2020-06-01 | Bible       |
| 2020-06-02 | Mask        |
| 2020-05-30 | T-Shirt     |
+------------+-------------+
<strong>输出：</strong>
+------------+----------+------------------------------+
| sell_date  | num_sold | products                     |
+------------+----------+------------------------------+
| 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
| 2020-06-01 | 2        | Bible,Pencil                 |
| 2020-06-02 | 1        | Mask                         |
+------------+----------+------------------------------+
<strong>解释：</strong>
对于2020-05-30，出售的物品是 (Headphone, Basketball, T-shirt)，按词典序排列，并用逗号 ',' 分隔。
对于2020-06-01，出售的物品是 (Pencil, Bible)，按词典序排列，并用逗号分隔。
对于2020-06-02，出售的物品是 (Mask)，只需返回该物品名。
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
SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1485. 克隆含随机指针的二叉树 🔒](https://leetcode.cn/problems/clone-binary-tree-with-random-pointer){#1485}

{{< tabs "1485" >}}

{{% tab "python" %}}
```python
# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random


class Solution:
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        def dfs(root):
            if root is None:
                return None
            if root in mp:
                return mp[root]
            copy = NodeCopy(root.val)
            mp[root] = copy
            copy.left = dfs(root.left)
            copy.right = dfs(root.right)
            copy.random = dfs(root.random)
            return copy

        mp = {}
        return dfs(root)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for Node.
 * public class Node {
 *     int val;
 *     Node left;
 *     Node right;
 *     Node random;
 *     Node() {}
 *     Node(int val) { this.val = val; }
 *     Node(int val, Node left, Node right, Node random) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *         this.random = random;
 *     }
 * }
 */

class Solution {
    private Map<Node, NodeCopy> mp;

    public NodeCopy copyRandomBinaryTree(Node root) {
        mp = new HashMap<>();
        return dfs(root);
    }

    private NodeCopy dfs(Node root) {
        if (root == null) {
            return null;
        }
        if (mp.containsKey(root)) {
            return mp.get(root);
        }
        NodeCopy copy = new NodeCopy(root.val);
        mp.put(root, copy);
        copy.left = dfs(root.left);
        copy.right = dfs(root.right);
        copy.random = dfs(root.random);
        return copy;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> mp;
        return dfs(root, mp);
    }

    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& mp) {
        if (!root) return nullptr;
        if (mp.count(root)) return mp[root];
        NodeCopy* copy = new NodeCopy(root->val);
        mp[root] = copy;
        copy->left = dfs(root->left, mp);
        copy->right = dfs(root->right, mp);
        copy->random = dfs(root->random, mp);
        return copy;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Random *Node
 * }
 */

func copyRandomBinaryTree(root *Node) *NodeCopy {
	mp := make(map[*Node]*NodeCopy)
	var dfs func(root *Node) *NodeCopy
	dfs = func(root *Node) *NodeCopy {
		if root == nil {
			return nil
		}
		if v, ok := mp[root]; ok {
			return v
		}
		copy := &NodeCopy{Val: root.Val}
		mp[root] = copy
		copy.Left = dfs(root.Left)
		copy.Right = dfs(root.Right)
		copy.Random = dfs(root.Random)
		return copy
	}
	return dfs(root)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉树，树中每个节点都含有一个附加的随机指针，该指针可以指向树中的任何节点或者指向空（<code>null</code>）。</p>

<p>请返回该树的 <strong><a href="https://baike.baidu.com/item/%E6%B7%B1%E6%8B%B7%E8%B4%9D/22785317?fr=aladdin" target="_blank">深拷贝</a></strong> 。</p>

<p>该树的输入/输出形式与普通二叉树相同，每个节点都用 <code>[val, random_index]</code> 表示：</p>

<ul>
	<li><code>val</code>：表示 <code>Node.val</code> 的整数</li>
	<li><code>random_index</code>：随机指针指向的节点（在输入的树数组中）的下标；如果未指向任何节点，则为 <code>null</code> 。</li>
</ul>

<p>该树以 <code>Node</code> 类的形式给出，而你需要以 <code>NodeCopy</code> 类的形式返回克隆得到的树。<code>NodeCopy</code> 类和<code>Node</code> 类定义一致。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1485.Clone%20Binary%20Tree%20With%20Random%20Pointer/images/clone_1.png" style="height: 473px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [[1,null],null,[4,3],[7,0]]
<strong>输出：</strong>[[1,null],null,[4,3],[7,0]]
<strong>解释：</strong>初始二叉树为 [1,null,4,7] 。
节点 1 的随机指针指向 null，所以表示为 [1, null] 。
节点 4 的随机指针指向 7，所以表示为 [4, 3] 其中 3 是树数组中节点 7 对应的下标。
节点 7 的随机指针指向 1，所以表示为 [7, 0] 其中 0 是树数组中节点 1 对应的下标。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1485.Clone%20Binary%20Tree%20With%20Random%20Pointer/images/clone_2.png" style="height: 540px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [[1,4],null,[1,0],null,[1,5],[1,5]]
<strong>输出：</strong>[[1,4],null,[1,0],null,[1,5],[1,5]]
<strong>解释：</strong>节点的随机指针可以指向它自身。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1485.Clone%20Binary%20Tree%20With%20Random%20Pointer/images/e2.png" style="height: 426px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
<strong>输出：</strong>[[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>tree</code> 中节点数目范围是 <code>[0, 1000]</code></li>
	<li>每个节点的值的范围是 <code>[1, 10^6]</code></li>
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
# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random


class Solution:
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        def dfs(root):
            if root is None:
                return None
            if root in mp:
                return mp[root]
            copy = NodeCopy(root.val)
            mp[root] = copy
            copy.left = dfs(root.left)
            copy.right = dfs(root.right)
            copy.random = dfs(root.random)
            return copy

        mp = {}
        return dfs(root)
```

#### Java

```java
/**
 * Definition for Node.
 * public class Node {
 *     int val;
 *     Node left;
 *     Node right;
 *     Node random;
 *     Node() {}
 *     Node(int val) { this.val = val; }
 *     Node(int val, Node left, Node right, Node random) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *         this.random = random;
 *     }
 * }
 */

class Solution {
    private Map<Node, NodeCopy> mp;

    public NodeCopy copyRandomBinaryTree(Node root) {
        mp = new HashMap<>();
        return dfs(root);
    }

    private NodeCopy dfs(Node root) {
        if (root == null) {
            return null;
        }
        if (mp.containsKey(root)) {
            return mp.get(root);
        }
        NodeCopy copy = new NodeCopy(root.val);
        mp.put(root, copy);
        copy.left = dfs(root.left);
        copy.right = dfs(root.right);
        copy.random = dfs(root.random);
        return copy;
    }
}
```

#### C++

```cpp
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> mp;
        return dfs(root, mp);
    }

    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& mp) {
        if (!root) return nullptr;
        if (mp.count(root)) return mp[root];
        NodeCopy* copy = new NodeCopy(root->val);
        mp[root] = copy;
        copy->left = dfs(root->left, mp);
        copy->right = dfs(root->right, mp);
        copy->random = dfs(root->random, mp);
        return copy;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Random *Node
 * }
 */

func copyRandomBinaryTree(root *Node) *NodeCopy {
	mp := make(map[*Node]*NodeCopy)
	var dfs func(root *Node) *NodeCopy
	dfs = func(root *Node) *NodeCopy {
		if root == nil {
			return nil
		}
		if v, ok := mp[root]; ok {
			return v
		}
		copy := &NodeCopy{Val: root.Val}
		mp[root] = copy
		copy.Left = dfs(root.Left)
		copy.Right = dfs(root.Right)
		copy.Random = dfs(root.Random)
		return copy
	}
	return dfs(root)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1486. 数组异或操作](https://leetcode.cn/problems/xor-operation-in-an-array){#1486}

{{< tabs "1486" >}}

{{% tab "python" %}}
```python
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        return reduce(xor, ((start + 2 * i) for i in range(n)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= start + 2 * i;
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
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func xorOperation(n int, start int) (ans int) {
	for i := 0; i < n; i++ {
		ans ^= start + 2*i
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function xorOperation(n: number, start: number): number {
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans ^= start + 2 * i;
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

<p>给你两个整数，<code>n</code> 和 <code>start</code> 。</p>

<p>数组 <code>nums</code> 定义为：<code>nums[i] = start + 2*i</code>（下标从 0 开始）且 <code>n == nums.length</code> 。</p>

<p>请返回 <code>nums</code> 中所有元素按位异或（<strong>XOR</strong>）后得到的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5, start = 0
<strong>输出：</strong>8
<strong>解释：</strong>数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     &quot;^&quot; 为按位异或 XOR 运算符。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4, start = 3
<strong>输出：</strong>8
<strong>解释：</strong>数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1, start = 7
<strong>输出：</strong>7
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 10, start = 5
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= start &lt;= 1000</code></li>
	<li><code>n == nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟算出数组中所有元素的异或结果。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        return reduce(xor, ((start + 2 * i) for i in range(n)))
```

#### Java

```java
class Solution {
    public int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
};
```

#### Go

```go
func xorOperation(n int, start int) (ans int) {
	for i := 0; i < n; i++ {
		ans ^= start + 2*i
	}
	return
}
```

#### TypeScript

```ts
function xorOperation(n: number, start: number): number {
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans ^= start + 2 * i;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1487. 保证文件名唯一](https://leetcode.cn/problems/making-file-names-unique){#1487}

{{< tabs "1487" >}}

{{% tab "python" %}}
```python
class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        d = defaultdict(int)
        for i, name in enumerate(names):
            if name in d:
                k = d[name]
                while f'{name}({k})' in d:
                    k += 1
                d[name] = k + 1
                names[i] = f'{name}({k})'
            d[names[i]] = 1
        return names
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < names.length; ++i) {
            if (d.containsKey(names[i])) {
                int k = d.get(names[i]);
                while (d.containsKey(names[i] + "(" + k + ")")) {
                    ++k;
                }
                d.put(names[i], k);
                names[i] += "(" + k + ")";
            }
            d.put(names[i], 1);
        }
        return names;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> d;
        for (auto& name : names) {
            int k = d[name];
            if (k) {
                while (d[name + "(" + to_string(k) + ")"]) {
                    k++;
                }
                d[name] = k;
                name += "(" + to_string(k) + ")";
            }
            d[name] = 1;
        }
        return names;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getFolderNames(names []string) []string {
	d := map[string]int{}
	for i, name := range names {
		if k, ok := d[name]; ok {
			for {
				newName := fmt.Sprintf("%s(%d)", name, k)
				if d[newName] == 0 {
					d[name] = k + 1
					names[i] = newName
					break
				}
				k++
			}
		}
		d[names[i]] = 1
	}
	return names
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getFolderNames(names: string[]): string[] {
    let d: Map<string, number> = new Map();
    for (let i = 0; i < names.length; ++i) {
        if (d.has(names[i])) {
            let k: number = d.get(names[i]) || 0;
            while (d.has(names[i] + '(' + k + ')')) {
                ++k;
            }
            d.set(names[i], k);
            names[i] += '(' + k + ')';
        }
        d.set(names[i], 1);
    }
    return names;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的字符串数组 <code>names</code> 。你将会在文件系统中创建 <code>n</code> 个文件夹：在第 <code>i</code> 分钟，新建名为 <code>names[i]</code> 的文件夹。</p>

<p>由于两个文件 <strong>不能</strong> 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 <code>(k)</code> 的形式为新文件夹的文件名添加后缀，其中 <code>k</code> 是能保证文件名唯一的 <strong>最小正整数</strong> 。</p>

<p>返回长度为<em> <code>n</code></em> 的字符串数组，其中 <code>ans[i]</code> 是创建第 <code>i</code> 个文件夹时系统分配给该文件夹的实际名称。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>names = [&quot;pes&quot;,&quot;fifa&quot;,&quot;gta&quot;,&quot;pes(2019)&quot;]
<strong>输出：</strong>[&quot;pes&quot;,&quot;fifa&quot;,&quot;gta&quot;,&quot;pes(2019)&quot;]
<strong>解释：</strong>文件系统将会这样创建文件名：
&quot;pes&quot; --&gt; 之前未分配，仍为 &quot;pes&quot;
&quot;fifa&quot; --&gt; 之前未分配，仍为 &quot;fifa&quot;
&quot;gta&quot; --&gt; 之前未分配，仍为 &quot;gta&quot;
&quot;pes(2019)&quot; --&gt; 之前未分配，仍为 &quot;pes(2019)&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>names = [&quot;gta&quot;,&quot;gta(1)&quot;,&quot;gta&quot;,&quot;avalon&quot;]
<strong>输出：</strong>[&quot;gta&quot;,&quot;gta(1)&quot;,&quot;gta(2)&quot;,&quot;avalon&quot;]
<strong>解释：</strong>文件系统将会这样创建文件名：
&quot;gta&quot; --&gt; 之前未分配，仍为 &quot;gta&quot;
&quot;gta(1)&quot; --&gt; 之前未分配，仍为 &quot;gta(1)&quot;
&quot;gta&quot; --&gt; 文件名被占用，系统为该名称添加后缀 (k)，由于 &quot;gta(1)&quot; 也被占用，所以 k = 2 。实际创建的文件名为 &quot;gta(2)&quot; 。
&quot;avalon&quot; --&gt; 之前未分配，仍为 &quot;avalon&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>names = [&quot;onepiece&quot;,&quot;onepiece(1)&quot;,&quot;onepiece(2)&quot;,&quot;onepiece(3)&quot;,&quot;onepiece&quot;]
<strong>输出：</strong>[&quot;onepiece&quot;,&quot;onepiece(1)&quot;,&quot;onepiece(2)&quot;,&quot;onepiece(3)&quot;,&quot;onepiece(4)&quot;]
<strong>解释：</strong>当创建最后一个文件夹时，最小的正有效 k 为 4 ，文件名变为 &quot;onepiece(4)&quot;。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>names = [&quot;wano&quot;,&quot;wano&quot;,&quot;wano&quot;,&quot;wano&quot;]
<strong>输出：</strong>[&quot;wano&quot;,&quot;wano(1)&quot;,&quot;wano(2)&quot;,&quot;wano(3)&quot;]
<strong>解释：</strong>每次创建文件夹 &quot;wano&quot; 时，只需增加后缀中 k 的值即可。</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>names = [&quot;kaido&quot;,&quot;kaido(1)&quot;,&quot;kaido&quot;,&quot;kaido(1)&quot;]
<strong>输出：</strong>[&quot;kaido&quot;,&quot;kaido(1)&quot;,&quot;kaido(2)&quot;,&quot;kaido(1)(1)&quot;]
<strong>解释：</strong>注意，如果含后缀文件名被占用，那么系统也会按规则在名称后添加新的后缀 (k) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= names.length &lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>names[i]</code> 由小写英文字母、数字和/或圆括号组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用哈希表 $d$ 记录每个文件夹的最小可用编号，其中 $d[name] = k$ 表示文件夹 $name$ 的最小可用编号为 $k$。初始时，$d$ 中没有任何文件夹，因此 $d$ 为空。

接下来遍历文件夹数组，对于每个文件名 $name$：

-   如果 $name$ 在 $d$ 中，说明文件夹 $name$ 已经存在，我们需要找到一个新的文件夹名字。我们可以不断地尝试 $name(k)$，其中 $k$ 从 $d[name]$ 开始，直到找到一个文件夹名字 $name(k)$ 不存在于 $d$ 中为止。我们将 $name(k)$ 加入 $d$ 中，并将 $d[name]$ 更新为 $k + 1$。然后我们将 $name$ 更新为 $name(k)$。
-   如果 $name$ 不在 $d$ 中，我们可以直接将 $name$ 加入 $d$ 中，并将 $d[name]$ 更新为 $1$。
-   接着我们将 $name$ 加入答案数组。然后继续遍历下一个文件名。

遍历完所有文件名后，我们即可得到答案数组。

> 在以下代码实现中，我们直接修改文件名数组 $names$，而不使用额外的答案数组。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为数组 $names$ 中所有文件名的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        d = defaultdict(int)
        for i, name in enumerate(names):
            if name in d:
                k = d[name]
                while f'{name}({k})' in d:
                    k += 1
                d[name] = k + 1
                names[i] = f'{name}({k})'
            d[names[i]] = 1
        return names
```

#### Java

```java
class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < names.length; ++i) {
            if (d.containsKey(names[i])) {
                int k = d.get(names[i]);
                while (d.containsKey(names[i] + "(" + k + ")")) {
                    ++k;
                }
                d.put(names[i], k);
                names[i] += "(" + k + ")";
            }
            d.put(names[i], 1);
        }
        return names;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> d;
        for (auto& name : names) {
            int k = d[name];
            if (k) {
                while (d[name + "(" + to_string(k) + ")"]) {
                    k++;
                }
                d[name] = k;
                name += "(" + to_string(k) + ")";
            }
            d[name] = 1;
        }
        return names;
    }
};
```

#### Go

```go
func getFolderNames(names []string) []string {
	d := map[string]int{}
	for i, name := range names {
		if k, ok := d[name]; ok {
			for {
				newName := fmt.Sprintf("%s(%d)", name, k)
				if d[newName] == 0 {
					d[name] = k + 1
					names[i] = newName
					break
				}
				k++
			}
		}
		d[names[i]] = 1
	}
	return names
}
```

#### TypeScript

```ts
function getFolderNames(names: string[]): string[] {
    let d: Map<string, number> = new Map();
    for (let i = 0; i < names.length; ++i) {
        if (d.has(names[i])) {
            let k: number = d.get(names[i]) || 0;
            while (d.has(names[i] + '(' + k + ')')) {
                ++k;
            }
            d.set(names[i], k);
            names[i] += '(' + k + ')';
        }
        d.set(names[i], 1);
    }
    return names;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1488. 避免洪水泛滥](https://leetcode.cn/problems/avoid-flood-in-the-city){#1488}

{{< tabs "1488" >}}

{{% tab "python" %}}
```python
class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        ans = [-1] * n
        sunny = SortedList()
        rainy = {}
        for i, v in enumerate(rains):
            if v:
                if v in rainy:
                    idx = sunny.bisect_right(rainy[v])
                    if idx == len(sunny):
                        return []
                    ans[sunny[idx]] = v
                    sunny.discard(sunny[idx])
                rainy[v] = i
            else:
                sunny.add(i)
                ans[i] = 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        TreeSet<Integer> sunny = new TreeSet<>();
        Map<Integer, Integer> rainy = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int v = rains[i];
            if (v > 0) {
                if (rainy.containsKey(v)) {
                    Integer t = sunny.higher(rainy.get(v));
                    if (t == null) {
                        return new int[0];
                    }
                    ans[t] = v;
                    sunny.remove(t);
                }
                rainy.put(v, i);
            } else {
                sunny.add(i);
                ans[i] = 1;
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
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> sunny;
        unordered_map<int, int> rainy;
        for (int i = 0; i < n; ++i) {
            int v = rains[i];
            if (v) {
                if (rainy.count(v)) {
                    auto it = sunny.upper_bound(rainy[v]);
                    if (it == sunny.end()) {
                        return {};
                    }
                    ans[*it] = v;
                    sunny.erase(it);
                }
                rainy[v] = i;
            } else {
                sunny.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func avoidFlood(rains []int) []int {
	n := len(rains)
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	sunny := []int{}
	rainy := map[int]int{}
	for i, v := range rains {
		if v > 0 {
			if j, ok := rainy[v]; ok {
				idx := sort.SearchInts(sunny, j+1)
				if idx == len(sunny) {
					return []int{}
				}
				ans[sunny[idx]] = v
				sunny = append(sunny[:idx], sunny[idx+1:]...)
			}
			rainy[v] = i
		} else {
			sunny = append(sunny, i)
			ans[i] = 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function avoidFlood(rains: number[]): number[] {
    const n = rains.length;
    const ans: number[] = new Array(n).fill(-1);
    const sunny: TreeSet<number> = new TreeSet<number>();
    const rainy: Map<number, number> = new Map<number, number>();
    for (let i = 0; i < n; ++i) {
        const v = rains[i];
        if (v > 0) {
            if (rainy.has(v)) {
                const t = sunny.higher(rainy.get(v)!);
                if (t === undefined) {
                    return [];
                }
                ans[t] = v;
                sunny.delete(t);
            }
            rainy.set(v, i);
        } else {
            sunny.add(i);
            ans[i] = 1;
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

class TreeSet<T = number> {
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
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
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
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
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

<p>你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 <code>n</code>&nbsp;个湖泊下雨前是空的，那么它就会装满水。如果第 <code>n</code>&nbsp;个湖泊下雨前是 <strong>满的&nbsp;</strong>，这个湖泊会发生 <strong>洪水</strong> 。你的目标是避免任意一个湖泊发生洪水。</p>

<p>给你一个整数数组&nbsp;<code>rains</code>&nbsp;，其中：</p>

<ul>
	<li><code>rains[i] &gt; 0</code>&nbsp;表示第 <code>i</code>&nbsp;天时，第 <code>rains[i]</code>&nbsp;个湖泊会下雨。</li>
	<li><code>rains[i] == 0</code>&nbsp;表示第 <code>i</code>&nbsp;天没有湖泊会下雨，你可以选择 <strong>一个</strong>&nbsp;湖泊并 <strong>抽干</strong>&nbsp;这个湖泊的水。</li>
</ul>

<p>请返回一个数组<em>&nbsp;</em><code>ans</code>&nbsp;，满足：</p>

<ul>
	<li><code>ans.length == rains.length</code></li>
	<li>如果&nbsp;<code>rains[i] &gt; 0</code> ，那么<code>ans[i] == -1</code>&nbsp;。</li>
	<li>如果&nbsp;<code>rains[i] == 0</code>&nbsp;，<code>ans[i]</code>&nbsp;是你第&nbsp;<code>i</code>&nbsp;天选择抽干的湖泊。</li>
</ul>

<p>如果有多种可行解，请返回它们中的 <strong>任意一个</strong>&nbsp;。如果没办法阻止洪水，请返回一个 <strong>空的数组</strong>&nbsp;。</p>

<p>请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,3,4]
<strong>输出：</strong>[-1,-1,-1,-1]
<strong>解释：</strong>第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，装满水的湖泊包括 [1,2,3]
第四天后，装满水的湖泊包括 [1,2,3,4]
没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,0,0,2,1]
<strong>输出：</strong>[-1,-1,2,1,-1,-1]
<strong>解释：</strong>第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
第五天后，装满水的湖泊包括 [2]。
第六天后，装满水的湖泊包括 [1,2]。
可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1] 也是另一个可行的没有洪水的方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,0,1,2]
<strong>输出：</strong>[]
<strong>解释：</strong>第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
但第三天后，湖泊 1 和 2 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rains.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= rains[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

我们将所有晴天都存入 $sunny$ 数组或者有序集合中，使用哈希表 $rainy$ 记录每个湖泊最近一次下雨的日期。初始化答案数组 $ans$ 每个元素为 $-1$。

接下来，我们遍历 $rains$ 数组。对于每个下雨的日期 $i$，如果 $rainy[rains[i]]$ 存在，说明该湖泊在之前下过雨，那么我们需要找到 $sunny$ 数组中第一个大于 $rainy[rains[i]]$ 的日期，将其替换为下雨的日期，否则说明无法阻止洪水，返回空数组。对于没下雨的日期 $i$，我们将 $i$ 存入 $sunny$ 数组中，并且将 $ans[i]$ 置为 $1$。

遍历结束，返回答案数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为 $rains$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        ans = [-1] * n
        sunny = SortedList()
        rainy = {}
        for i, v in enumerate(rains):
            if v:
                if v in rainy:
                    idx = sunny.bisect_right(rainy[v])
                    if idx == len(sunny):
                        return []
                    ans[sunny[idx]] = v
                    sunny.discard(sunny[idx])
                rainy[v] = i
            else:
                sunny.add(i)
                ans[i] = 1
        return ans
```

#### Java

```java
class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        TreeSet<Integer> sunny = new TreeSet<>();
        Map<Integer, Integer> rainy = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int v = rains[i];
            if (v > 0) {
                if (rainy.containsKey(v)) {
                    Integer t = sunny.higher(rainy.get(v));
                    if (t == null) {
                        return new int[0];
                    }
                    ans[t] = v;
                    sunny.remove(t);
                }
                rainy.put(v, i);
            } else {
                sunny.add(i);
                ans[i] = 1;
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
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> sunny;
        unordered_map<int, int> rainy;
        for (int i = 0; i < n; ++i) {
            int v = rains[i];
            if (v) {
                if (rainy.count(v)) {
                    auto it = sunny.upper_bound(rainy[v]);
                    if (it == sunny.end()) {
                        return {};
                    }
                    ans[*it] = v;
                    sunny.erase(it);
                }
                rainy[v] = i;
            } else {
                sunny.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func avoidFlood(rains []int) []int {
	n := len(rains)
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	sunny := []int{}
	rainy := map[int]int{}
	for i, v := range rains {
		if v > 0 {
			if j, ok := rainy[v]; ok {
				idx := sort.SearchInts(sunny, j+1)
				if idx == len(sunny) {
					return []int{}
				}
				ans[sunny[idx]] = v
				sunny = append(sunny[:idx], sunny[idx+1:]...)
			}
			rainy[v] = i
		} else {
			sunny = append(sunny, i)
			ans[i] = 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function avoidFlood(rains: number[]): number[] {
    const n = rains.length;
    const ans: number[] = new Array(n).fill(-1);
    const sunny: TreeSet<number> = new TreeSet<number>();
    const rainy: Map<number, number> = new Map<number, number>();
    for (let i = 0; i < n; ++i) {
        const v = rains[i];
        if (v > 0) {
            if (rainy.has(v)) {
                const t = sunny.higher(rainy.get(v)!);
                if (t === undefined) {
                    return [];
                }
                ans[t] = v;
                sunny.delete(t);
            }
            rainy.set(v, i);
        } else {
            sunny.add(i);
            ans[i] = 1;
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

class TreeSet<T = number> {
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
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
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
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1489. 找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree){#1489}

{{< tabs "1489" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.n = n

    def union(self, a, b):
        if self.find(a) == self.find(b):
            return False
        self.p[self.find(a)] = self.find(b)
        self.n -= 1
        return True

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


class Solution:
    def findCriticalAndPseudoCriticalEdges(
        self, n: int, edges: List[List[int]]
    ) -> List[List[int]]:
        for i, e in enumerate(edges):
            e.append(i)
        edges.sort(key=lambda x: x[2])
        uf = UnionFind(n)
        v = sum(w for f, t, w, _ in edges if uf.union(f, t))
        ans = [[], []]
        for f, t, w, i in edges:
            uf = UnionFind(n)
            k = sum(z for x, y, z, j in edges if j != i and uf.union(x, y))
            if uf.n > 1 or (uf.n == 1 and k > v):
                ans[0].append(i)
                continue

            uf = UnionFind(n)
            uf.union(f, t)
            k = w + sum(z for x, y, z, j in edges if j != i and uf.union(x, y))
            if k == v:
                ans[1].append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        for (int i = 0; i < edges.length; ++i) {
            int[] e = edges[i];
            int[] t = new int[4];
            System.arraycopy(e, 0, t, 0, 3);
            t[3] = i;
            edges[i] = t;
        }
        Arrays.sort(edges, Comparator.comparingInt(a -> a[2]));
        int v = 0;
        UnionFind uf = new UnionFind(n);
        for (int[] e : edges) {
            int f = e[0], t = e[1], w = e[2];
            if (uf.union(f, t)) {
                v += w;
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < 2; ++i) {
            ans.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1], w = e[2], i = e[3];
            uf = new UnionFind(n);
            int k = 0;
            for (int[] ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && uf.union(x, y)) {
                    k += z;
                }
            }
            if (uf.getN() > 1 || (uf.getN() == 1 && k > v)) {
                ans.get(0).add(i);
                continue;
            }
            uf = new UnionFind(n);
            uf.union(f, t);
            k = w;
            for (int[] ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && uf.union(x, y)) {
                    k += z;
                }
            }
            if (k == v) {
                ans.get(1).add(i);
            }
        }
        return ans;
    }
}

class UnionFind {
    private int[] p;
    private int n;

    public UnionFind(int n) {
        p = new int[n];
        this.n = n;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    public int getN() {
        return n;
    }

    public boolean union(int a, int b) {
        if (find(a) == find(b)) {
            return false;
        }
        p[find(a)] = find(b);
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
        if (find(a) == find(b)) return false;
        p[find(a)] = find(b);
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int v = 0;
        UnionFind uf(n);
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2];
            if (uf.unite(f, t)) v += w;
        }
        vector<vector<int>> ans(2);
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2], i = e[3];
            UnionFind ufa(n);
            int k = 0;
            for (auto& ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && ufa.unite(x, y)) k += z;
            }
            if (ufa.n > 1 || (ufa.n == 1 && k > v)) {
                ans[0].push_back(i);
                continue;
            }

            UnionFind ufb(n);
            ufb.unite(f, t);
            k = w;
            for (auto& ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && ufb.unite(x, y)) k += z;
            }
            if (k == v) ans[1].push_back(i);
        }
        return ans;
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

func findCriticalAndPseudoCriticalEdges(n int, edges [][]int) [][]int {
	for i := range edges {
		edges[i] = append(edges[i], i)
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i][2] < edges[j][2]
	})
	v := 0
	uf := newUnionFind(n)
	for _, e := range edges {
		f, t, w := e[0], e[1], e[2]
		if uf.union(f, t) {
			v += w
		}
	}
	ans := make([][]int, 2)
	for _, e := range edges {
		f, t, w, i := e[0], e[1], e[2], e[3]
		uf = newUnionFind(n)
		k := 0
		for _, ne := range edges {
			x, y, z, j := ne[0], ne[1], ne[2], ne[3]
			if j != i && uf.union(x, y) {
				k += z
			}
		}
		if uf.n > 1 || (uf.n == 1 && k > v) {
			ans[0] = append(ans[0], i)
			continue
		}
		uf = newUnionFind(n)
		uf.union(f, t)
		k = w
		for _, ne := range edges {
			x, y, z, j := ne[0], ne[1], ne[2], ne[3]
			if j != i && uf.union(x, y) {
				k += z
			}
		}
		if k == v {
			ans[1] = append(ans[1], i)
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

<p>给你一个 <code>n</code>&nbsp;个点的带权无向连通图，节点编号为 <code>0</code>&nbsp;到 <code>n-1</code>&nbsp;，同时还有一个数组 <code>edges</code>&nbsp;，其中 <code>edges[i] = [from</code><code><sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;表示在&nbsp;<code>from<sub>i</sub></code>&nbsp;和&nbsp;<code>to<sub>i</sub></code>&nbsp;节点之间有一条带权无向边。最小生成树&nbsp;(MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。</p>

<p>请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。</p>

<p>请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1489.Find%20Critical%20and%20Pseudo-Critical%20Edges%20in%20Minimum%20Spanning%20Tree/images/ex1.png" style="height: 262px; width: 259px;"></p>

<pre><strong>输入：</strong>n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
<strong>输出：</strong>[[0,1],[2,3,4,5]]
<strong>解释：</strong>上图描述了给定图。
下图是所有的最小生成树。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1489.Find%20Critical%20and%20Pseudo-Critical%20Edges%20in%20Minimum%20Spanning%20Tree/images/msts.png" style="height: 553px; width: 540px;">
注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
</pre>

<p><strong>示例 2 ：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1489.Find%20Critical%20and%20Pseudo-Critical%20Edges%20in%20Minimum%20Spanning%20Tree/images/ex2.png" style="height: 253px; width: 247px;"></p>

<pre><strong>输入：</strong>n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
<strong>输出：</strong>[[],[0,1,2,3]]
<strong>解释：</strong>可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(200, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub> &lt; to<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= weight<sub>i</sub>&nbsp;&lt;= 1000</code></li>
	<li>所有 <code>(from<sub>i</sub>, to<sub>i</sub>)</code>&nbsp;数对都是互不相同的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Kruskal 算法

先利用 Kruskal 算法，得出最小生成树的权值 v。然后依次枚举每条边，按上面的方法，判断是否是关键边；如果不是关键边，再判断是否是伪关键边。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.n = n

    def union(self, a, b):
        if self.find(a) == self.find(b):
            return False
        self.p[self.find(a)] = self.find(b)
        self.n -= 1
        return True

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


class Solution:
    def findCriticalAndPseudoCriticalEdges(
        self, n: int, edges: List[List[int]]
    ) -> List[List[int]]:
        for i, e in enumerate(edges):
            e.append(i)
        edges.sort(key=lambda x: x[2])
        uf = UnionFind(n)
        v = sum(w for f, t, w, _ in edges if uf.union(f, t))
        ans = [[], []]
        for f, t, w, i in edges:
            uf = UnionFind(n)
            k = sum(z for x, y, z, j in edges if j != i and uf.union(x, y))
            if uf.n > 1 or (uf.n == 1 and k > v):
                ans[0].append(i)
                continue

            uf = UnionFind(n)
            uf.union(f, t)
            k = w + sum(z for x, y, z, j in edges if j != i and uf.union(x, y))
            if k == v:
                ans[1].append(i)
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        for (int i = 0; i < edges.length; ++i) {
            int[] e = edges[i];
            int[] t = new int[4];
            System.arraycopy(e, 0, t, 0, 3);
            t[3] = i;
            edges[i] = t;
        }
        Arrays.sort(edges, Comparator.comparingInt(a -> a[2]));
        int v = 0;
        UnionFind uf = new UnionFind(n);
        for (int[] e : edges) {
            int f = e[0], t = e[1], w = e[2];
            if (uf.union(f, t)) {
                v += w;
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < 2; ++i) {
            ans.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1], w = e[2], i = e[3];
            uf = new UnionFind(n);
            int k = 0;
            for (int[] ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && uf.union(x, y)) {
                    k += z;
                }
            }
            if (uf.getN() > 1 || (uf.getN() == 1 && k > v)) {
                ans.get(0).add(i);
                continue;
            }
            uf = new UnionFind(n);
            uf.union(f, t);
            k = w;
            for (int[] ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && uf.union(x, y)) {
                    k += z;
                }
            }
            if (k == v) {
                ans.get(1).add(i);
            }
        }
        return ans;
    }
}

class UnionFind {
    private int[] p;
    private int n;

    public UnionFind(int n) {
        p = new int[n];
        this.n = n;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    public int getN() {
        return n;
    }

    public boolean union(int a, int b) {
        if (find(a) == find(b)) {
            return false;
        }
        p[find(a)] = find(b);
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
        if (find(a) == find(b)) return false;
        p[find(a)] = find(b);
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int v = 0;
        UnionFind uf(n);
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2];
            if (uf.unite(f, t)) v += w;
        }
        vector<vector<int>> ans(2);
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2], i = e[3];
            UnionFind ufa(n);
            int k = 0;
            for (auto& ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && ufa.unite(x, y)) k += z;
            }
            if (ufa.n > 1 || (ufa.n == 1 && k > v)) {
                ans[0].push_back(i);
                continue;
            }

            UnionFind ufb(n);
            ufb.unite(f, t);
            k = w;
            for (auto& ne : edges) {
                int x = ne[0], y = ne[1], z = ne[2], j = ne[3];
                if (j != i && ufb.unite(x, y)) k += z;
            }
            if (k == v) ans[1].push_back(i);
        }
        return ans;
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

func findCriticalAndPseudoCriticalEdges(n int, edges [][]int) [][]int {
	for i := range edges {
		edges[i] = append(edges[i], i)
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i][2] < edges[j][2]
	})
	v := 0
	uf := newUnionFind(n)
	for _, e := range edges {
		f, t, w := e[0], e[1], e[2]
		if uf.union(f, t) {
			v += w
		}
	}
	ans := make([][]int, 2)
	for _, e := range edges {
		f, t, w, i := e[0], e[1], e[2], e[3]
		uf = newUnionFind(n)
		k := 0
		for _, ne := range edges {
			x, y, z, j := ne[0], ne[1], ne[2], ne[3]
			if j != i && uf.union(x, y) {
				k += z
			}
		}
		if uf.n > 1 || (uf.n == 1 && k > v) {
			ans[0] = append(ans[0], i)
			continue
		}
		uf = newUnionFind(n)
		uf.union(f, t)
		k = w
		for _, ne := range edges {
			x, y, z, j := ne[0], ne[1], ne[2], ne[3]
			if j != i && uf.union(x, y) {
				k += z
			}
		}
		if k == v {
			ans[1] = append(ans[1], i)
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
