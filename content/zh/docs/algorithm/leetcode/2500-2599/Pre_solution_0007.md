---
title: "2560_打家劫舍 IV"
date: 2025-10-08T18:39:23+08:00
weight: 7
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 字符串, 排序, 数学, 数组, 模拟, 线段树, 脑筋急转弯, 贪心]
---

{{< markmap >}}
### [2560_打家劫舍 IV](#2560)
#### [贪心](#2560)
#### [数组](#2560)
#### [二分查找](#2560)
#### [动态规划](#2560)
### [2561_重排水果](#2561)
#### [贪心](#2561)
#### [排序](#2561)
#### [数组](#2561)
#### [哈希表](#2561)
### [2562_找出数组的串联值](#2562)
#### [数组](#2562)
#### [双指针](#2562)
#### [模拟](#2562)
### [2563_统计公平数对的数目](#2563)
#### [数组](#2563)
#### [双指针](#2563)
#### [二分查找](#2563)
#### [排序](#2563)
### [2564_子字符串异或查询](#2564)
#### [位运算](#2564)
#### [数组](#2564)
#### [哈希表](#2564)
#### [字符串](#2564)
### [2565_最少得分子序列](#2565)
#### [双指针](#2565)
#### [字符串](#2565)
#### [二分查找](#2565)
### [2566_替换一个数字后的最大差值](#2566)
#### [贪心](#2566)
#### [数学](#2566)
### [2567_修改两个元素的最小分数](#2567)
#### [贪心](#2567)
#### [数组](#2567)
#### [排序](#2567)
### [2568_最小无法得到的或值](#2568)
#### [位运算](#2568)
#### [脑筋急转弯](#2568)
#### [数组](#2568)
### [2569_更新数组后处理求和查询](#2569)
#### [线段树](#2569)
#### [数组](#2569)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2560_打家劫舍 IV
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 2561_重排水果
___
#### 贪心
___
#### 排序
___
#### 数组
___
#### 哈希表
---
### 2562_找出数组的串联值
___
#### 数组
___
#### 双指针
___
#### 模拟
---
### 2563_统计公平数对的数目
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2564_子字符串异或查询
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2565_最少得分子序列
___
#### 双指针
___
#### 字符串
___
#### 二分查找
---
### 2566_替换一个数字后的最大差值
___
#### 贪心
___
#### 数学
---
### 2567_修改两个元素的最小分数
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2568_最小无法得到的或值
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
---
### 2569_更新数组后处理求和查询
___
#### 线段树
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 排序 | 数学 | 数组 |
| 模拟 | 线段树 | 脑筋急转弯 |
| 贪心 |  |  |

# [2560. 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv){#2560}

{{< tabs "2560" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def f(x):
            cnt, j = 0, -2
            for i, v in enumerate(nums):
                if v > x or i == j + 1:
                    continue
                cnt += 1
                j = i
            return cnt >= k

        return bisect_left(range(max(nums) + 1), True, key=f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCapability(int[] nums, int k) {
        int left = 0, right = (int) 1e9;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (f(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int f(int[] nums, int x) {
        int cnt = 0, j = -2;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > x || i == j + 1) {
                continue;
            }
            ++cnt;
            j = i;
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto f = [&](int x) {
            int cnt = 0, j = -2;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > x || i == j + 1) {
                    continue;
                }
                ++cnt;
                j = i;
            }
            return cnt >= k;
        };
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) >> 1;
            if (f(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCapability(nums []int, k int) int {
	return sort.Search(1e9+1, func(x int) bool {
		cnt, j := 0, -2
		for i, v := range nums {
			if v > x || i == j+1 {
				continue
			}
			cnt++
			j = i
		}
		return cnt >= k
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCapability(nums: number[], k: number): number {
    const f = (mx: number): boolean => {
        let cnt = 0;
        let j = -2;
        for (let i = 0; i < nums.length; ++i) {
            if (nums[i] <= mx && i - j > 1) {
                ++cnt;
                j = i;
            }
        }
        return cnt >= k;
    };

    let left = 1;
    let right = Math.max(...nums);
    while (left < right) {
        const mid = (left + right) >> 1;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>沿街有一排连续的房屋。每间房屋内都藏有一定的现金。现在有一位小偷计划从这些房屋中窃取现金。</p>

<p>由于相邻的房屋装有相互连通的防盗系统，所以小偷 <strong>不会窃取相邻的房屋</strong> 。</p>

<p>小偷的 <strong>窃取能力</strong> 定义为他在窃取过程中能从单间房屋中窃取的 <strong>最大金额</strong> 。</p>

<p>给你一个整数数组 <code>nums</code> 表示每间房屋存放的现金金额。形式上，从左起第 <code>i</code> 间房屋中放有 <code>nums[i]</code> 美元。</p>

<p>另给你一个整数&nbsp;<code>k</code> ，表示窃贼将会窃取的 <strong>最少</strong> 房屋数。小偷总能窃取至少 <code>k</code> 间房屋。</p>

<p>返回小偷的 <strong>最小</strong> 窃取能力。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,5,9], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>
小偷窃取至少 2 间房屋，共有 3 种方式：
- 窃取下标 0 和 2 处的房屋，窃取能力为 max(nums[0], nums[2]) = 5 。
- 窃取下标 0 和 3 处的房屋，窃取能力为 max(nums[0], nums[3]) = 9 。
- 窃取下标 1 和 3 处的房屋，窃取能力为 max(nums[1], nums[3]) = 9 。
因此，返回 min(5, 9, 9) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,9,3,1], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>共有 7 种窃取方式。窃取能力最小的情况所对应的方式是窃取下标 0 和 4 处的房屋。返回 max(nums[0], nums[4]) = 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= (nums.length + 1)/2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 贪心

题目求的是窃贼的最小窃取能力，我们可以二分枚举窃贼的窃取能力，对于枚举的能力 $x$，我们可以通过贪心的方式判断窃贼是否能够窃取至少 $k$ 间房屋，具体地，我们从左到右遍历数组，对于当前遍历到的房屋 $i$，如果 $nums[i] \leq x$ 且 $i$ 与上一个窃取的房屋的下标之差大于 $1$，则窃贼可以窃取房屋 $i$，否则窃贼不能窃取房屋 $i$。累计窃取的房屋数，如果窃取的房屋数大于等于 $k$，则说明窃贼可以窃取至少 $k$ 间房屋，此时窃贼的窃取能力 $x$ 可能是最小的，否则窃贼的窃取能力 $x$ 不是最小的。

时间复杂度 $O(n \times \log m)$，空间复杂度 $O(1)$。其中 $n$ 和 $m$ 分别是数组 $nums$ 的长度和数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def f(x):
            cnt, j = 0, -2
            for i, v in enumerate(nums):
                if v > x or i == j + 1:
                    continue
                cnt += 1
                j = i
            return cnt >= k

        return bisect_left(range(max(nums) + 1), True, key=f)
```

#### Java

```java
class Solution {
    public int minCapability(int[] nums, int k) {
        int left = 0, right = (int) 1e9;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (f(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int f(int[] nums, int x) {
        int cnt = 0, j = -2;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] > x || i == j + 1) {
                continue;
            }
            ++cnt;
            j = i;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto f = [&](int x) {
            int cnt = 0, j = -2;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > x || i == j + 1) {
                    continue;
                }
                ++cnt;
                j = i;
            }
            return cnt >= k;
        };
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) >> 1;
            if (f(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func minCapability(nums []int, k int) int {
	return sort.Search(1e9+1, func(x int) bool {
		cnt, j := 0, -2
		for i, v := range nums {
			if v > x || i == j+1 {
				continue
			}
			cnt++
			j = i
		}
		return cnt >= k
	})
}
```

#### TypeScript

```ts
function minCapability(nums: number[], k: number): number {
    const f = (mx: number): boolean => {
        let cnt = 0;
        let j = -2;
        for (let i = 0; i < nums.length; ++i) {
            if (nums[i] <= mx && i - j > 1) {
                ++cnt;
                j = i;
            }
        }
        return cnt >= k;
    };

    let left = 1;
    let right = Math.max(...nums);
    while (left < right) {
        const mid = (left + right) >> 1;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2561. 重排水果](https://leetcode.cn/problems/rearranging-fruits){#2561}

{{< tabs "2561" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        cnt = Counter()
        for a, b in zip(basket1, basket2):
            cnt[a] += 1
            cnt[b] -= 1
        mi = min(cnt)
        nums = []
        for x, v in cnt.items():
            if v % 2:
                return -1
            nums.extend([x] * (abs(v) // 2))
        nums.sort()
        m = len(nums) // 2
        return sum(min(x, mi * 2) for x in nums[:m])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            cnt.merge(basket1[i], 1, Integer::sum);
            cnt.merge(basket2[i], -1, Integer::sum);
        }
        int mi = 1 << 30;
        List<Integer> nums = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (v % 2 != 0) {
                return -1;
            }
            for (int i = Math.abs(v) / 2; i > 0; --i) {
                nums.add(x);
            }
            mi = Math.min(mi, x);
        }
        Collections.sort(nums);
        int m = nums.size();
        long ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            ans += Math.min(nums.get(i), mi * 2);
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
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        int mi = 1 << 30;
        vector<int> nums;
        for (auto& [x, v] : cnt) {
            if (v % 2) {
                return -1;
            }
            for (int i = abs(v) / 2; i; --i) {
                nums.push_back(x);
            }
            mi = min(mi, x);
        }
        ranges::sort(nums);
        int m = nums.size();
        long long ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            ans += min(nums[i], mi * 2);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(basket1 []int, basket2 []int) (ans int64) {
	cnt := map[int]int{}
	for i, a := range basket1 {
		cnt[a]++
		cnt[basket2[i]]--
	}
	mi := 1 << 30
	nums := []int{}
	for x, v := range cnt {
		if v%2 != 0 {
			return -1
		}
		for i := abs(v) / 2; i > 0; i-- {
			nums = append(nums, x)
		}
		mi = min(mi, x)
	}
	sort.Ints(nums)
	m := len(nums)
	for i := 0; i < m/2; i++ {
		ans += int64(min(nums[i], mi*2))
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
function minCost(basket1: number[], basket2: number[]): number {
    const n = basket1.length;
    const cnt: Map<number, number> = new Map();
    for (let i = 0; i < n; i++) {
        cnt.set(basket1[i], (cnt.get(basket1[i]) || 0) + 1);
        cnt.set(basket2[i], (cnt.get(basket2[i]) || 0) - 1);
    }
    let mi = Number.MAX_SAFE_INTEGER;
    const nums: number[] = [];
    for (const [x, v] of cnt.entries()) {
        if (v % 2 !== 0) {
            return -1;
        }
        for (let i = 0; i < Math.abs(v) / 2; i++) {
            nums.push(x);
        }
        mi = Math.min(mi, x);
    }

    nums.sort((a, b) => a - b);
    const m = nums.length;
    let ans = 0;
    for (let i = 0; i < m / 2; i++) {
        ans += Math.min(nums[i], mi * 2);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let n = basket1.len();
        let mut cnt: HashMap<i32, i32> = HashMap::new();

        for i in 0..n {
            *cnt.entry(basket1[i]).or_insert(0) += 1;
            *cnt.entry(basket2[i]).or_insert(0) -= 1;
        }

        let mut mi = i32::MAX;
        let mut nums = Vec::new();

        for (x, v) in cnt {
            if v % 2 != 0 {
                return -1;
            }
            for _ in 0..(v.abs() / 2) {
                nums.push(x);
            }
            mi = mi.min(x);
        }

        nums.sort();

        let m = nums.len();
        let mut ans = 0;

        for i in 0..(m / 2) {
            ans += nums[i].min(mi * 2) as i64;
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

<p>你有两个果篮，每个果篮中有 <code>n</code> 个水果。给你两个下标从 <strong>0</strong> 开始的整数数组 <code>basket1</code> 和 <code>basket2</code> ，用以表示两个果篮中每个水果的交换成本。你想要让两个果篮相等。为此，可以根据需要多次执行下述操作：</p>

<ul>
	<li>选中两个下标 <code>i</code> 和 <code>j</code> ，并交换 <code>basket1</code> 中的第 <code>i</code> 个水果和 <code>basket2</code> 中的第 <code>j</code> 个水果。</li>
	<li>交换的成本是 <code>min(basket1<sub>i</sub>,basket2<sub>j</sub>)</code> 。</li>
</ul>

<p>根据果篮中水果的成本进行排序，如果排序后结果完全相同，则认为两个果篮相等。</p>

<p>返回使两个果篮相等的最小交换成本，如果无法使两个果篮相等，则返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>basket1 = [4,2,2,2], basket2 = [1,4,1,2]
<strong>输出：</strong>1
<strong>解释：</strong>交换 basket1 中下标为 1 的水果和 basket2 中下标为 0 的水果，交换的成本为 1 。此时，basket1 = [4,1,2,2] 且 basket2 = [2,4,1,2] 。重排两个数组，发现二者相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>basket1 = [2,3,4,1], basket2 = [3,2,5,1]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明无法使两个果篮相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>basket1.length == basket2.length</code></li>
	<li><code>1 &lt;= basket1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= basket1<sub>i</sub>,basket2<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

我们可以先将两个数组中共有的元素去掉，对于剩下的每个数字，其出现的次数必须为偶数，否则无法构造出相同的数组。不妨记去除共有元素后，两数组分别为 $a$ 和 $b$。

接下来，我们考虑如何进行交换。

如果我们要交换 $a$ 中最小的数，那么我们要在 $b$ 中找到最大的数，与其进行交换；同理，如果我们要交换 $b$ 中最小的数，那么我们要在 $a$ 中找到最大的数，与其进行交换。可以通过排序来实现。

不过，还有另一种交换的方案，我们可以借助一个最小的数 $mi$ 作为过渡元素，将 $a$ 中的数先与 $mi$ 进行交换，再将 $mi$ 与 $b$ 中的数进行交换。这样，交换的成本为 $2 \times mi$。

在代码实现上，我们可以直接将数组 $a$ 和 $b$ 合并成数组 $nums$，然后对数组 $nums$ 进行排序。接下来枚举前一半的数，计算每次的最小成本，累加到答案中即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        cnt = Counter()
        for a, b in zip(basket1, basket2):
            cnt[a] += 1
            cnt[b] -= 1
        mi = min(cnt)
        nums = []
        for x, v in cnt.items():
            if v % 2:
                return -1
            nums.extend([x] * (abs(v) // 2))
        nums.sort()
        m = len(nums) // 2
        return sum(min(x, mi * 2) for x in nums[:m])
```

#### Java

```java
class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            cnt.merge(basket1[i], 1, Integer::sum);
            cnt.merge(basket2[i], -1, Integer::sum);
        }
        int mi = 1 << 30;
        List<Integer> nums = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (v % 2 != 0) {
                return -1;
            }
            for (int i = Math.abs(v) / 2; i > 0; --i) {
                nums.add(x);
            }
            mi = Math.min(mi, x);
        }
        Collections.sort(nums);
        int m = nums.size();
        long ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            ans += Math.min(nums.get(i), mi * 2);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        int mi = 1 << 30;
        vector<int> nums;
        for (auto& [x, v] : cnt) {
            if (v % 2) {
                return -1;
            }
            for (int i = abs(v) / 2; i; --i) {
                nums.push_back(x);
            }
            mi = min(mi, x);
        }
        ranges::sort(nums);
        int m = nums.size();
        long long ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            ans += min(nums[i], mi * 2);
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(basket1 []int, basket2 []int) (ans int64) {
	cnt := map[int]int{}
	for i, a := range basket1 {
		cnt[a]++
		cnt[basket2[i]]--
	}
	mi := 1 << 30
	nums := []int{}
	for x, v := range cnt {
		if v%2 != 0 {
			return -1
		}
		for i := abs(v) / 2; i > 0; i-- {
			nums = append(nums, x)
		}
		mi = min(mi, x)
	}
	sort.Ints(nums)
	m := len(nums)
	for i := 0; i < m/2; i++ {
		ans += int64(min(nums[i], mi*2))
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
function minCost(basket1: number[], basket2: number[]): number {
    const n = basket1.length;
    const cnt: Map<number, number> = new Map();
    for (let i = 0; i < n; i++) {
        cnt.set(basket1[i], (cnt.get(basket1[i]) || 0) + 1);
        cnt.set(basket2[i], (cnt.get(basket2[i]) || 0) - 1);
    }
    let mi = Number.MAX_SAFE_INTEGER;
    const nums: number[] = [];
    for (const [x, v] of cnt.entries()) {
        if (v % 2 !== 0) {
            return -1;
        }
        for (let i = 0; i < Math.abs(v) / 2; i++) {
            nums.push(x);
        }
        mi = Math.min(mi, x);
    }

    nums.sort((a, b) => a - b);
    const m = nums.length;
    let ans = 0;
    for (let i = 0; i < m / 2; i++) {
        ans += Math.min(nums[i], mi * 2);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let n = basket1.len();
        let mut cnt: HashMap<i32, i32> = HashMap::new();

        for i in 0..n {
            *cnt.entry(basket1[i]).or_insert(0) += 1;
            *cnt.entry(basket2[i]).or_insert(0) -= 1;
        }

        let mut mi = i32::MAX;
        let mut nums = Vec::new();

        for (x, v) in cnt {
            if v % 2 != 0 {
                return -1;
            }
            for _ in 0..(v.abs() / 2) {
                nums.push(x);
            }
            mi = mi.min(x);
        }

        nums.sort();

        let m = nums.len();
        let mut ans = 0;

        for i in 0..(m / 2) {
            ans += nums[i].min(mi * 2) as i64;
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

# [2562. 找出数组的串联值](https://leetcode.cn/problems/find-the-array-concatenation-value){#2562}

{{< tabs "2562" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        i, j = 0, len(nums) - 1
        while i < j:
            ans += int(str(nums[i]) + str(nums[j]))
            i, j = i + 1, j - 1
        if i == j:
            ans += nums[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long ans = 0;
        int i = 0, j = nums.length - 1;
        for (; i < j; ++i, --j) {
            ans += Integer.parseInt(nums[i] + "" + nums[j]);
        }
        if (i == j) {
            ans += nums[i];
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
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        for (; i < j; ++i, --j) {
            ans += stoi(to_string(nums[i]) + to_string(nums[j]));
        }
        if (i == j) {
            ans += nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheArrayConcVal(nums []int) (ans int64) {
	i, j := 0, len(nums)-1
	for ; i < j; i, j = i+1, j-1 {
		x, _ := strconv.Atoi(strconv.Itoa(nums[i]) + strconv.Itoa(nums[j]))
		ans += int64(x)
	}
	if i == j {
		ans += int64(nums[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheArrayConcVal(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    let i = 0;
    let j = n - 1;
    while (i < j) {
        ans += Number(`${nums[i]}${nums[j]}`);
        i++;
        j--;
    }
    if (i === j) {
        ans += nums[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        let mut ans = 0;
        let mut n = nums.len();

        for i in 0..n / 2 {
            ans += format!("{}{}", nums[i], nums[n - i - 1])
                .parse::<i64>()
                .unwrap();
        }

        if n % 2 != 0 {
            ans += nums[n / 2] as i64;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int getLen(int num) {
    int res = 0;
    while (num) {
        num /= 10;
        res++;
    }
    return res;
}

long long findTheArrayConcVal(int* nums, int numsSize) {
    long long ans = 0;
    int i = 0;
    int j = numsSize - 1;
    while (i < j) {
        ans += nums[i] * pow(10, getLen(nums[j])) + nums[j];
        i++;
        j--;
    }
    if (i == j) {
        ans += nums[i];
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组&nbsp;<code>nums</code> 。</p>

<p>现定义两个数字的 <strong>串联</strong>&nbsp;是由这两个数值串联起来形成的新数字。</p>

<ul>
	<li>例如，<code>15</code><span style="">&nbsp;和&nbsp;</span><code>49</code>&nbsp;的串联是&nbsp;<code>1549</code> 。</li>
</ul>

<p><code>nums</code>&nbsp;的 <strong>串联值</strong>&nbsp;最初等于 <code>0</code> 。执行下述操作直到&nbsp;<code>nums</code>&nbsp;变为空：</p>

<ul>
	<li>如果&nbsp;<code>nums</code>&nbsp;的长度大于 1，分别选中 <code>nums</code> 中的第一个元素和最后一个元素，将二者串联得到的值加到&nbsp;<code>nums</code>&nbsp;的 <strong>串联值</strong> 上，然后从&nbsp;<code>nums</code>&nbsp;中删除第一个和最后一个元素。例如，如果&nbsp;<code>nums</code> 是 <code>[1, 2, 4, 5, 6]</code>，将 16 添加到串联值。</li>
	<li>如果&nbsp;<code>nums</code>&nbsp;中仅存在一个元素，则将该元素的值加到&nbsp;<code>nums</code> 的串联值上，然后删除这个元素。</li>
</ul>

<p>返回执行完所有操作后<em>&nbsp;</em><code>nums</code> 的串联值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [7,52,2,4]
<b>输出：</b>596
<b>解释：</b>在执行任一步操作前，nums 为 [7,52,2,4] ，串联值为 0 。
 - 在第一步操作中：
我们选中第一个元素 7 和最后一个元素 4 。
二者的串联是 74 ，将其加到串联值上，所以串联值等于 74 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [52,2] 。
 - 在第二步操作中： 
我们选中第一个元素 52 和最后一个元素 2 。 
二者的串联是 522 ，将其加到串联值上，所以串联值等于 596 。
接着我们从 nums 中移除这两个元素，所以 nums 变为空。
由于串联值等于 596 ，所以答案就是 596 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,14,13,8,12]
<b>输出：</b>673
<b>解释：</b>在执行任一步操作前，nums 为 [5,14,13,8,12] ，串联值为 0 。 
- 在第一步操作中： 
我们选中第一个元素 5 和最后一个元素 12 。 
二者的串联是 512 ，将其加到串联值上，所以串联值等于 512 。 
接着我们从 nums 中移除这两个元素，所以 nums 变为 [14,13,8] 。
- 在第二步操作中：
我们选中第一个元素 14 和最后一个元素 8 。
二者的串联是 148 ，将其加到串联值上，所以串联值等于 660 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [13] 。 
- 在第三步操作中：
nums 只有一个元素，所以我们选中 13 并将其加到串联值上，所以串联值等于 673 。
接着我们从 nums 中移除这个元素，所以 nums 变为空。 
由于串联值等于 673 ，所以答案就是 673 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

从数组两端开始，每次取出一个元素，将其与另一个元素拼接，然后将拼接后的结果加到答案中。重复这个过程，直到数组为空。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 和 $M$ 分别是数组的长度和数组中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        i, j = 0, len(nums) - 1
        while i < j:
            ans += int(str(nums[i]) + str(nums[j]))
            i, j = i + 1, j - 1
        if i == j:
            ans += nums[i]
        return ans
```

#### Java

```java
class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long ans = 0;
        int i = 0, j = nums.length - 1;
        for (; i < j; ++i, --j) {
            ans += Integer.parseInt(nums[i] + "" + nums[j]);
        }
        if (i == j) {
            ans += nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        for (; i < j; ++i, --j) {
            ans += stoi(to_string(nums[i]) + to_string(nums[j]));
        }
        if (i == j) {
            ans += nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func findTheArrayConcVal(nums []int) (ans int64) {
	i, j := 0, len(nums)-1
	for ; i < j; i, j = i+1, j-1 {
		x, _ := strconv.Atoi(strconv.Itoa(nums[i]) + strconv.Itoa(nums[j]))
		ans += int64(x)
	}
	if i == j {
		ans += int64(nums[i])
	}
	return
}
```

#### TypeScript

```ts
function findTheArrayConcVal(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    let i = 0;
    let j = n - 1;
    while (i < j) {
        ans += Number(`${nums[i]}${nums[j]}`);
        i++;
        j--;
    }
    if (i === j) {
        ans += nums[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut ans = 0;
        let mut i = 0;
        let mut j = n - 1;
        while i < j {
            ans += format!("{}{}", nums[i], nums[j]).parse::<i64>().unwrap();
            i += 1;
            j -= 1;
        }
        if i == j {
            ans += nums[i] as i64;
        }
        ans
    }
}
```

#### C

```c
int getLen(int num) {
    int res = 0;
    while (num) {
        num /= 10;
        res++;
    }
    return res;
}

long long findTheArrayConcVal(int* nums, int numsSize) {
    long long ans = 0;
    int i = 0;
    int j = numsSize - 1;
    while (i < j) {
        ans += nums[i] * pow(10, getLen(nums[j])) + nums[j];
        i++;
        j--;
    }
    if (i == j) {
        ans += nums[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        let mut ans = 0;
        let mut n = nums.len();

        for i in 0..n / 2 {
            ans += format!("{}{}", nums[i], nums[n - i - 1])
                .parse::<i64>()
                .unwrap();
        }

        if n % 2 != 0 {
            ans += nums[n / 2] as i64;
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

# [2563. 统计公平数对的数目](https://leetcode.cn/problems/count-the-number-of-fair-pairs){#2563}

{{< tabs "2563" >}}

{{% tab "python" %}}
```python
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        for i, x in enumerate(nums):
            j = bisect_left(nums, lower - x, lo=i + 1)
            k = bisect_left(nums, upper - x + 1, lo=i + 1)
            ans += k - j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = search(nums, lower - nums[i], i + 1);
            int k = search(nums, upper - nums[i] + 1, i + 1);
            ans += k - j;
        }
        return ans;
    }

    private int search(int[] nums, int x, int left) {
        int right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto k = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            ans += k - j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countFairPairs(nums []int, lower int, upper int) (ans int64) {
	sort.Ints(nums)
	for i, x := range nums {
		j := sort.Search(len(nums), func(h int) bool { return h > i && nums[h] >= lower-x })
		k := sort.Search(len(nums), func(h int) bool { return h > i && nums[h] >= upper-x+1 })
		ans += int64(k - j)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countFairPairs(nums: number[], lower: number, upper: number): number {
    const search = (x: number, l: number): number => {
        let r = nums.length;
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

    nums.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        const j = search(lower - nums[i], i + 1);
        const k = search(upper - nums[i] + 1, i + 1);
        ans += k - j;
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

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code>&nbsp;，和两个整数&nbsp;<code>lower</code> 和&nbsp;<code>upper</code> ，返回 <strong>公平数对的数目</strong> 。</p>

<p>如果&nbsp;<code>(i, j)</code>&nbsp;数对满足以下情况，则认为它是一个 <strong>公平数对</strong>&nbsp;：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code>，且</li>
	<li><code>lower &lt;= nums[i] + nums[j] &lt;= upper</code></li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>nums = [0,1,7,4,4,5], lower = 3, upper = 6
<b>输出：</b>6
<b>解释：</b>共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>nums = [1,7,9,2,5], lower = 11, upper = 11
<b>输出：</b>1
<b>解释：</b>只有单个公平数对：(2,3) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= lower &lt;= upper &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们先对数组 `nums` 按照升序排序，然后枚举 `nums[i]`，对于每个 `nums[i]`，我们通过二分查找找到 `nums[j]` 的下界 `j`，即第一个满足 `nums[j] >= lower - nums[i]` 的下标，然后再通过二分查找找到 `nums[k]` 的下界 `k`，即第一个满足 `nums[k] >= upper - nums[i] + 1` 的下标，那么 `[j, k)` 即为 `nums[j]` 满足 `lower <= nums[i] + nums[j] <= upper` 的下标范围，这些下标对应的 `nums[j]` 的个数即为 `k - j`，将其累加到答案中即可。注意 $j \gt i$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        for i, x in enumerate(nums):
            j = bisect_left(nums, lower - x, lo=i + 1)
            k = bisect_left(nums, upper - x + 1, lo=i + 1)
            ans += k - j
        return ans
```

#### Java

```java
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = search(nums, lower - nums[i], i + 1);
            int k = search(nums, upper - nums[i] + 1, i + 1);
            ans += k - j;
        }
        return ans;
    }

    private int search(int[] nums, int x, int left) {
        int right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto k = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            ans += k - j;
        }
        return ans;
    }
};
```

#### Go

```go
func countFairPairs(nums []int, lower int, upper int) (ans int64) {
	sort.Ints(nums)
	for i, x := range nums {
		j := sort.Search(len(nums), func(h int) bool { return h > i && nums[h] >= lower-x })
		k := sort.Search(len(nums), func(h int) bool { return h > i && nums[h] >= upper-x+1 })
		ans += int64(k - j)
	}
	return
}
```

#### TypeScript

```ts
function countFairPairs(nums: number[], lower: number, upper: number): number {
    const search = (x: number, l: number): number => {
        let r = nums.length;
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

    nums.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        const j = search(lower - nums[i], i + 1);
        const k = search(upper - nums[i] + 1, i + 1);
        ans += k - j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2564. 子字符串异或查询](https://leetcode.cn/problems/substring-xor-queries){#2564}

{{< tabs "2564" >}}

{{% tab "python" %}}
```python
class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        d = {}
        n = len(s)
        for i in range(n):
            x = 0
            for j in range(32):
                if i + j >= n:
                    break
                x = x << 1 | int(s[i + j])
                if x not in d:
                    d[x] = [i, i + j]
                if x == 0:
                    break
        return [d.get(first ^ second, [-1, -1]) for first, second in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] substringXorQueries(String s, int[][] queries) {
        Map<Integer, int[]> d = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < 32 && i + j < n; ++j) {
                x = x << 1 | (s.charAt(i + j) - '0');
                d.putIfAbsent(x, new int[] {i, i + j});
                if (x == 0) {
                    break;
                }
            }
        }
        int m = queries.length;
        int[][] ans = new int[m][2];
        for (int i = 0; i < m; ++i) {
            int first = queries[i][0], second = queries[i][1];
            int val = first ^ second;
            ans[i] = d.getOrDefault(val, new int[] {-1, -1});
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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> d;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < 32 && i + j < n; ++j) {
                x = x << 1 | (s[i + j] - '0');
                if (!d.count(x)) {
                    d[x] = {i, i + j};
                }
                if (x == 0) {
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& q : queries) {
            int first = q[0], second = q[1];
            int val = first ^ second;
            if (d.count(val)) {
                ans.emplace_back(d[val]);
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func substringXorQueries(s string, queries [][]int) (ans [][]int) {
	d := map[int][]int{}
	for i := range s {
		x := 0
		for j := 0; j < 32 && i+j < len(s); j++ {
			x = x<<1 | int(s[i+j]-'0')
			if _, ok := d[x]; !ok {
				d[x] = []int{i, i + j}
			}
			if x == 0 {
				break
			}
		}
	}
	for _, q := range queries {
		first, second := q[0], q[1]
		val := first ^ second
		if v, ok := d[val]; ok {
			ans = append(ans, v)
		} else {
			ans = append(ans, []int{-1, -1})
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>二进制字符串</strong>&nbsp;<code>s</code>&nbsp;和一个整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [first<sub>i</sub>, second<sub>i</sub>]</code>&nbsp;。</p>

<p>对于第&nbsp;<code>i</code>&nbsp;个查询，找到 <code>s</code>&nbsp;的 <strong>最短子字符串</strong>&nbsp;，它对应的 <strong>十进制</strong>值&nbsp;<code>val</code>&nbsp;与&nbsp;<code>first<sub>i</sub></code>&nbsp;<b>按位异或</b>&nbsp;得到&nbsp;<code>second<sub>i</sub></code>&nbsp;，换言之，<code>val ^ first<sub>i</sub> == second<sub>i</sub></code>&nbsp;。</p>

<p>第&nbsp;<code>i</code>&nbsp;个查询的答案是子字符串&nbsp;<code>[left<sub>i</sub>, right<sub>i</sub>]</code> 的两个端点（下标从&nbsp;<strong>0</strong>&nbsp;开始），如果不存在这样的子字符串，则答案为&nbsp;<code>[-1, -1]</code>&nbsp;。如果有多个答案，请你选择&nbsp;<code>left<sub>i</sub></code>&nbsp;最小的一个。</p>

<p>请你返回一个数组&nbsp;<code>ans</code>&nbsp;，其中&nbsp;<code>ans[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个查询的答案。</p>

<p><strong>子字符串</strong>&nbsp;是一个字符串中一段连续非空的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "101101", queries = [[0,5],[1,2]]
<b>输出：</b>[[0,2],[2,3]]
<b>解释：</b>第一个查询，端点为 <code>[0,2]</code> 的子字符串为 <strong>"101"</strong> ，对应十进制数字 <strong><code>5 ，且</code></strong> <strong><code>5 ^ 0 = 5</code></strong>&nbsp;，所以第一个查询的答案为 <code>[0,2]。第二个查询中，</code>端点为 <code>[2,3] 的子字符串为 </code><strong>"11" ，对应十进制数字</strong> <strong>3</strong>&nbsp;，且 <strong>3<code> ^ 1 = 2</code></strong><code>&nbsp;。所以第二个查询的答案为</code> <code>[2,3]</code> 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "0101", queries = [[12,8]]
<b>输出：</b>[[-1,-1]]
<b>解释：</b>这个例子中，没有符合查询的答案，所以返回 <code>[-1,-1] 。</code>
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "1", queries = [[4,5]]
<b>输出：</b>[[0,0]]
<b>解释：</b>这个例子中，端点为 <code>[0,0]</code> 的子字符串对应的十进制值为 <strong><code>1</code></strong><code>&nbsp;，且</code> <strong><code>1 ^ 4 = 5</code></strong><code>&nbsp;。所以答案为</code> <code>[0,0] 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code>&nbsp;。</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= first<sub>i</sub>, second<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们可以先预处理出所有长度为 $1$ 到 $32$ 的子串对应的十进制值，找到每个值对应的最小下标以及对应的右端点下标，存放在哈希表 $d$ 中。

然后枚举每个查询，对于每个查询 $[first, second]$，我们只需要在哈希表 $d$ 中查找是否存在键为 $first \oplus second$ 的键值对，如果存在，把对应的最小下标和右端点下标加入答案数组即可，否则加入 $[-1, -1]$。

时间复杂度 $O(n \times \log M + m)$，空间复杂度 $O(n \times \log M)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 和查询数组 $queries$ 的长度，而 $M$ 可以取整数的最大值 $2^{31} - 1$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        d = {}
        n = len(s)
        for i in range(n):
            x = 0
            for j in range(32):
                if i + j >= n:
                    break
                x = x << 1 | int(s[i + j])
                if x not in d:
                    d[x] = [i, i + j]
                if x == 0:
                    break
        return [d.get(first ^ second, [-1, -1]) for first, second in queries]
```

#### Java

```java
class Solution {
    public int[][] substringXorQueries(String s, int[][] queries) {
        Map<Integer, int[]> d = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < 32 && i + j < n; ++j) {
                x = x << 1 | (s.charAt(i + j) - '0');
                d.putIfAbsent(x, new int[] {i, i + j});
                if (x == 0) {
                    break;
                }
            }
        }
        int m = queries.length;
        int[][] ans = new int[m][2];
        for (int i = 0; i < m; ++i) {
            int first = queries[i][0], second = queries[i][1];
            int val = first ^ second;
            ans[i] = d.getOrDefault(val, new int[] {-1, -1});
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> d;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int x = 0;
            for (int j = 0; j < 32 && i + j < n; ++j) {
                x = x << 1 | (s[i + j] - '0');
                if (!d.count(x)) {
                    d[x] = {i, i + j};
                }
                if (x == 0) {
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& q : queries) {
            int first = q[0], second = q[1];
            int val = first ^ second;
            if (d.count(val)) {
                ans.emplace_back(d[val]);
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func substringXorQueries(s string, queries [][]int) (ans [][]int) {
	d := map[int][]int{}
	for i := range s {
		x := 0
		for j := 0; j < 32 && i+j < len(s); j++ {
			x = x<<1 | int(s[i+j]-'0')
			if _, ok := d[x]; !ok {
				d[x] = []int{i, i + j}
			}
			if x == 0 {
				break
			}
		}
	}
	for _, q := range queries {
		first, second := q[0], q[1]
		val := first ^ second
		if v, ok := d[val]; ok {
			ans = append(ans, v)
		} else {
			ans = append(ans, []int{-1, -1})
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2565. 最少得分子序列](https://leetcode.cn/problems/subsequence-with-the-minimum-score){#2565}

{{< tabs "2565" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        def check(x):
            for k in range(n):
                i, j = k - 1, k + x
                l = f[i] if i >= 0 else -1
                r = g[j] if j < n else m + 1
                if l < r:
                    return True
            return False

        m, n = len(s), len(t)
        f = [inf] * n
        g = [-1] * n
        i, j = 0, 0
        while i < m and j < n:
            if s[i] == t[j]:
                f[j] = i
                j += 1
            i += 1
        i, j = m - 1, n - 1
        while i >= 0 and j >= 0:
            if s[i] == t[j]:
                g[j] = i
                j -= 1
            i -= 1

        return bisect_left(range(n + 1), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[] f;
    private int[] g;

    public int minimumScore(String s, String t) {
        m = s.length();
        n = t.length();
        f = new int[n];
        g = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = 1 << 30;
            g[i] = -1;
        }
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                f[j] = i;
                ++j;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i) {
            if (s.charAt(i) == t.charAt(j)) {
                g[j] = i;
                --j;
            }
        }
        int l = 0, r = n;
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

    private boolean check(int len) {
        for (int k = 0; k < n; ++k) {
            int i = k - 1, j = k + len;
            int l = i >= 0 ? f[i] : -1;
            int r = j < n ? g[j] : m + 1;
            if (l < r) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> f(n, 1e6);
        vector<int> g(n, -1);
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (s[i] == t[j]) {
                f[j] = i;
                ++j;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i) {
            if (s[i] == t[j]) {
                g[j] = i;
                --j;
            }
        }

        auto check = [&](int len) {
            for (int k = 0; k < n; ++k) {
                int i = k - 1, j = k + len;
                int l = i >= 0 ? f[i] : -1;
                int r = j < n ? g[j] : m + 1;
                if (l < r) {
                    return true;
                }
            }
            return false;
        };

        int l = 0, r = n;
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
func minimumScore(s string, t string) int {
	m, n := len(s), len(t)
	f := make([]int, n)
	g := make([]int, n)
	for i := range f {
		f[i] = 1 << 30
		g[i] = -1
	}
	for i, j := 0, 0; i < m && j < n; i++ {
		if s[i] == t[j] {
			f[j] = i
			j++
		}
	}
	for i, j := m-1, n-1; i >= 0 && j >= 0; i-- {
		if s[i] == t[j] {
			g[j] = i
			j--
		}
	}
	return sort.Search(n+1, func(x int) bool {
		for k := 0; k < n; k++ {
			i, j := k-1, k+x
			l, r := -1, m+1
			if i >= 0 {
				l = f[i]
			}
			if j < n {
				r = g[j]
			}
			if l < r {
				return true
			}
		}
		return false
	})
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;。</p>

<p>你可以从字符串 <code>t</code>&nbsp;中删除任意数目的字符。</p>

<p>如果没有从字符串&nbsp;<code>t</code>&nbsp;中删除字符，那么得分为&nbsp;<code>0</code>&nbsp;，否则：</p>

<ul>
	<li>令&nbsp;<code>left</code>&nbsp;为删除字符中的最小下标。</li>
	<li>令&nbsp;<code>right</code>&nbsp;为删除字符中的最大下标。</li>
</ul>

<p>字符串的得分为&nbsp;<code>right - left + 1</code>&nbsp;。</p>

<p>请你返回使<em>&nbsp;</em><code>t</code><em> </em>成为<em>&nbsp;</em><code>s</code>&nbsp;子序列的最小得分。</p>

<p>一个字符串的 <strong>子序列</strong>&nbsp;是从原字符串中删除一些字符后（也可以一个也不删除），剩余字符不改变顺序得到的字符串。（比方说&nbsp;<code>"ace"</code> 是&nbsp;<code>"<strong><em>a</em></strong>b<strong><em>c</em></strong>d<strong><em>e</em></strong>"</code>&nbsp;的子序列，但是&nbsp;<code>"aec"</code>&nbsp;不是）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abacaba", t = "bzaa"
<b>输出：</b>1
<b>解释：</b>这个例子中，我们删除下标 1 处的字符 "z" （下标从 0 开始）。
字符串 t 变为 "baa" ，它是字符串 "abacaba" 的子序列，得分为 1 - 1 + 1 = 1 。
1 是能得到的最小得分。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "cde", t = "xyz"
<b>输出：</b>3
<b>解释：</b>这个例子中，我们将下标为 0， 1 和 2 处的字符 "x" ，"y" 和 "z" 删除（下标从 0 开始）。
字符串变成 "" ，它是字符串 "cde" 的子序列，得分为 2 - 0 + 1 = 3 。
3 是能得到的最小得分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前后缀预处理 + 二分查找

根据题目我们知道，删除字符的下标范围是 `[left, right]`，最优的做法一定是删除 `[left, right]` 范围内的所有字符。也就是说，我们要删除字符串 $t$ 中的一个子串，使得字符串 $t$ 的剩余前缀可以匹配字符串 $s$ 的前缀，字符串 $t$ 的剩余后缀可以匹配字符串 $s$ 的后缀，且字符串 $s$ 的前后缀不相交。注意，这里的匹配指的是子序列匹配。

因此，我们可以先预处理得到数组 $f$ 和 $g$，其中 $f[i]$ 表示字符串 $t$ 的前缀 $t[0,..i]$ 中，最少与字符串前 $[0,..f[i]]$ 个字符匹配；同理 $g[i]$ 表示字符串 $t$ 的后缀 $t[i,..n-1]$ 中，最多与字符串后 $[g[i],..n-1]$ 个字符匹配。

而删除字符的长度具备单调性，如果删除长度为 $x$ 的字符串后，满足条件，那么删除长度为 $x+1$ 的字符串也一定满足条件。因此，我们可以使用二分查找的方法，找到最小的满足条件的长度。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $t$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        def check(x):
            for k in range(n):
                i, j = k - 1, k + x
                l = f[i] if i >= 0 else -1
                r = g[j] if j < n else m + 1
                if l < r:
                    return True
            return False

        m, n = len(s), len(t)
        f = [inf] * n
        g = [-1] * n
        i, j = 0, 0
        while i < m and j < n:
            if s[i] == t[j]:
                f[j] = i
                j += 1
            i += 1
        i, j = m - 1, n - 1
        while i >= 0 and j >= 0:
            if s[i] == t[j]:
                g[j] = i
                j -= 1
            i -= 1

        return bisect_left(range(n + 1), True, key=check)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[] f;
    private int[] g;

    public int minimumScore(String s, String t) {
        m = s.length();
        n = t.length();
        f = new int[n];
        g = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = 1 << 30;
            g[i] = -1;
        }
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                f[j] = i;
                ++j;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i) {
            if (s.charAt(i) == t.charAt(j)) {
                g[j] = i;
                --j;
            }
        }
        int l = 0, r = n;
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

    private boolean check(int len) {
        for (int k = 0; k < n; ++k) {
            int i = k - 1, j = k + len;
            int l = i >= 0 ? f[i] : -1;
            int r = j < n ? g[j] : m + 1;
            if (l < r) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> f(n, 1e6);
        vector<int> g(n, -1);
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (s[i] == t[j]) {
                f[j] = i;
                ++j;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i) {
            if (s[i] == t[j]) {
                g[j] = i;
                --j;
            }
        }

        auto check = [&](int len) {
            for (int k = 0; k < n; ++k) {
                int i = k - 1, j = k + len;
                int l = i >= 0 ? f[i] : -1;
                int r = j < n ? g[j] : m + 1;
                if (l < r) {
                    return true;
                }
            }
            return false;
        };

        int l = 0, r = n;
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
func minimumScore(s string, t string) int {
	m, n := len(s), len(t)
	f := make([]int, n)
	g := make([]int, n)
	for i := range f {
		f[i] = 1 << 30
		g[i] = -1
	}
	for i, j := 0, 0; i < m && j < n; i++ {
		if s[i] == t[j] {
			f[j] = i
			j++
		}
	}
	for i, j := m-1, n-1; i >= 0 && j >= 0; i-- {
		if s[i] == t[j] {
			g[j] = i
			j--
		}
	}
	return sort.Search(n+1, func(x int) bool {
		for k := 0; k < n; k++ {
			i, j := k-1, k+x
			l, r := -1, m+1
			if i >= 0 {
				l = f[i]
			}
			if j < n {
				r = g[j]
			}
			if l < r {
				return true
			}
		}
		return false
	})
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2566. 替换一个数字后的最大差值](https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit){#2566}

{{< tabs "2566" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        mi = int(s.replace(s[0], '0'))
        for c in s:
            if c != '9':
                return int(s.replace(c, '9')) - mi
        return num - mi
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMaxDifference(int num) {
        String s = String.valueOf(num);
        int mi = Integer.parseInt(s.replace(s.charAt(0), '0'));
        for (char c : s.toCharArray()) {
            if (c != '9') {
                return Integer.parseInt(s.replace(c, '9')) - mi;
            }
        }
        return num - mi;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        char first = s[0];
        for (char& c : s) {
            if (c == first) {
                c = '0';
            }
        }
        int mi = stoi(s);
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '9') {
                char second = t[i];
                for (int j = i; j < t.size(); ++j) {
                    if (t[j] == second) {
                        t[j] = '9';
                    }
                }
                return stoi(t) - mi;
            }
        }
        return num - mi;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMaxDifference(num int) int {
	s := []byte(strconv.Itoa(num))
	first := s[0]
	for i := range s {
		if s[i] == first {
			s[i] = '0'
		}
	}
	mi, _ := strconv.Atoi(string(s))
	t := []byte(strconv.Itoa(num))
	for i := range t {
		if t[i] != '9' {
			second := t[i]
			for j := i; j < len(t); j++ {
				if t[j] == second {
					t[j] = '9'
				}
			}
			mx, _ := strconv.Atoi(string(t))
			return mx - mi
		}
	}
	return num - mi
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMaxDifference(num: number): number {
    const s = num.toString();
    const mi = +s.replaceAll(s[0], '0');
    for (const c of s) {
        if (c !== '9') {
            const mx = +s.replaceAll(c, '9');
            return mx - mi;
        }
    }
    return num - mi;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        let s = num.to_string();
        let mi = s.replace(s.chars().next().unwrap(), "0").parse::<i32>().unwrap();
        for c in s.chars() {
            if c != '9' {
                let mx = s.replace(c, "9").parse::<i32>().unwrap();
                return mx - mi;
            }
        }
        num - mi
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function (num) {
    const s = num.toString();
    const mi = +s.replaceAll(s[0], '0');
    for (const c of s) {
        if (c !== '9') {
            const mx = +s.replaceAll(c, '9');
            return mx - mi;
        }
    }
    return num - mi;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minMaxDifference(int num) {
    char s[12];
    sprintf(s, "%d", num);

    int mi;
    {
        char tmp[12];
        char t = s[0];
        for (int i = 0; s[i]; i++) {
            tmp[i] = (s[i] == t) ? '0' : s[i];
        }
        tmp[strlen(s)] = '\0';
        mi = atoi(tmp);
    }

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c != '9') {
            char tmp[12];
            for (int j = 0; s[j]; j++) {
                tmp[j] = (s[j] == c) ? '9' : s[j];
            }
            tmp[strlen(s)] = '\0';
            return atoi(tmp) - mi;
        }
    }

    return num - mi;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>num</code>&nbsp;。你知道 Danny Mittal 会偷偷将 <code>0</code>&nbsp;到 <code>9</code>&nbsp;中的一个数字 <strong>替换</strong> 成另一个数字。</p>

<p>请你返回将 <code>num</code>&nbsp;中&nbsp;<strong>恰好一个</strong>&nbsp;数字进行替换后，得到的最大值和最小值的差为多少。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>当 Danny 将一个数字 <code>d1</code> 替换成另一个数字 <code>d2</code> 时，Danny 需要将&nbsp;<code>num</code>&nbsp;中所有 <code>d1</code>&nbsp;都替换成&nbsp;<code>d2</code>&nbsp;。</li>
	<li>Danny 可以将一个数字替换成它自己，也就是说&nbsp;<code>num</code>&nbsp;可以不变。</li>
	<li>Danny 可以将数字分别替换成两个不同的数字分别得到最大值和最小值。</li>
	<li>替换后得到的数字可以包含前导 0 。</li>
	<li>Danny Mittal 获得周赛 326 前 10 名，让我们恭喜他。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 11891
<b>输出：</b>99009
<b>解释：</b>
为了得到最大值，我们将数字 1 替换成数字 9 ，得到 99899 。
为了得到最小值，我们将数字 1 替换成数字 0 ，得到 890 。
两个数字的差值为 99009 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 90
<b>输出：</b>99
<strong>解释：</strong>
可以得到的最大值是 99（将 0 替换成 9），最小值是 0（将 9 替换成 0）。
所以我们得到 99 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先将数字转为字符串 $s$。

要得到最小值，我们只需要将找到字符串 $s$ 的第一个数字 $s[0]$，然后把字符串中所有的 $s[0]$ 替换成 $0$ 即可。

要得到最大值，我们需要找到字符串 $s$ 中第一个不是 $9$ 的数字 $s[i]$，然后把字符串中所有的 $s[i]$ 替换成 $9$ 即可。

最后返回最大值和最小值的差即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数字 $\textit{num}$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        mi = int(s.replace(s[0], '0'))
        for c in s:
            if c != '9':
                return int(s.replace(c, '9')) - mi
        return num - mi
```

#### Java

```java
class Solution {
    public int minMaxDifference(int num) {
        String s = String.valueOf(num);
        int mi = Integer.parseInt(s.replace(s.charAt(0), '0'));
        for (char c : s.toCharArray()) {
            if (c != '9') {
                return Integer.parseInt(s.replace(c, '9')) - mi;
            }
        }
        return num - mi;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        char first = s[0];
        for (char& c : s) {
            if (c == first) {
                c = '0';
            }
        }
        int mi = stoi(s);
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '9') {
                char second = t[i];
                for (int j = i; j < t.size(); ++j) {
                    if (t[j] == second) {
                        t[j] = '9';
                    }
                }
                return stoi(t) - mi;
            }
        }
        return num - mi;
    }
};
```

#### Go

```go
func minMaxDifference(num int) int {
	s := []byte(strconv.Itoa(num))
	first := s[0]
	for i := range s {
		if s[i] == first {
			s[i] = '0'
		}
	}
	mi, _ := strconv.Atoi(string(s))
	t := []byte(strconv.Itoa(num))
	for i := range t {
		if t[i] != '9' {
			second := t[i]
			for j := i; j < len(t); j++ {
				if t[j] == second {
					t[j] = '9'
				}
			}
			mx, _ := strconv.Atoi(string(t))
			return mx - mi
		}
	}
	return num - mi
}
```

#### TypeScript

```ts
function minMaxDifference(num: number): number {
    const s = num.toString();
    const mi = +s.replaceAll(s[0], '0');
    for (const c of s) {
        if (c !== '9') {
            const mx = +s.replaceAll(c, '9');
            return mx - mi;
        }
    }
    return num - mi;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        let s = num.to_string();
        let mi = s.replace(s.chars().next().unwrap(), "0").parse::<i32>().unwrap();
        for c in s.chars() {
            if c != '9' {
                let mx = s.replace(c, "9").parse::<i32>().unwrap();
                return mx - mi;
            }
        }
        num - mi
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function (num) {
    const s = num.toString();
    const mi = +s.replaceAll(s[0], '0');
    for (const c of s) {
        if (c !== '9') {
            const mx = +s.replaceAll(c, '9');
            return mx - mi;
        }
    }
    return num - mi;
};
```

#### C

```c
int minMaxDifference(int num) {
    char s[12];
    sprintf(s, "%d", num);

    int mi;
    {
        char tmp[12];
        char t = s[0];
        for (int i = 0; s[i]; i++) {
            tmp[i] = (s[i] == t) ? '0' : s[i];
        }
        tmp[strlen(s)] = '\0';
        mi = atoi(tmp);
    }

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c != '9') {
            char tmp[12];
            for (int j = 0; s[j]; j++) {
                tmp[j] = (s[j] == c) ? '9' : s[j];
            }
            tmp[strlen(s)] = '\0';
            return atoi(tmp) - mi;
        }
    }

    return num - mi;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2567. 修改两个元素的最小分数](https://leetcode.cn/problems/minimum-score-by-changing-two-elements){#2567}

{{< tabs "2567" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        return min(nums[-1] - nums[2], nums[-2] - nums[1], nums[-3] - nums[0])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int a = nums[n - 1] - nums[2];
        int b = nums[n - 2] - nums[1];
        int c = nums[n - 3] - nums[0];
        return Math.min(a, Math.min(b, c));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeSum(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	return min(nums[n-1]-nums[2], min(nums[n-2]-nums[1], nums[n-3]-nums[0]))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeSum(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    return Math.min(nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        (nums[n - 1] - nums[2])
            .min(nums[n - 2] - nums[1])
            .min(nums[n - 3] - nums[0])
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minimizeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return min(nums[numsSize - 1] - nums[2], min(nums[numsSize - 2] - nums[1], nums[numsSize - 3] - nums[0]));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<ul>
	<li><code>nums</code> 的 <strong>最小</strong>&nbsp;得分是满足 <code>0 &lt;= i &lt; j &lt; nums.length</code>&nbsp;的&nbsp;<code>|nums[i]&nbsp;- nums[j]|</code>&nbsp;的最小值。</li>
	<li><code>nums</code>的 <strong>最大 </strong>得分是满足 <code>0 &lt;= i &lt; j &lt; nums.length</code>&nbsp;的&nbsp;<code>|nums[i]&nbsp;- nums[j]|</code>&nbsp;的最大值。</li>
	<li><code>nums</code>&nbsp;的分数是 <strong>最大</strong>&nbsp;得分与 <strong>最小</strong>&nbsp;得分的和。</li>
</ul>

<p>我们的目标是最小化&nbsp;<code>nums</code>&nbsp;的分数。你 <strong>最多</strong> 可以修改&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>2</strong>&nbsp;个元素的值。</p>

<p>请你返回修改&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>至多两个</strong>&nbsp;元素的值后，可以得到的 <strong>最小分数</strong>&nbsp;。</p>

<p><code>|x|</code>&nbsp;表示 <code>x</code>&nbsp;的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,3]
<b>输出：</b>0
<b>解释：</b>将 nums[1] 和 nums[2] 的值改为 1 ，nums 变为 [1,1,1] 。<code>|nums[i] - nums[j]|</code> 的值永远为 0 ，所以我们返回 0 + 0 = 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,7,8,5]
<b>输出：</b>3
<b>解释：
</b>将 nums[0] 和 nums[1] 的值变为 6 ，nums 变为 [6,6,7,8,5] 。
最小得分是 i = 0 且 j = 1 时得到的 |<code>nums[i] - nums[j]</code>| = |6 - 6| = 0 。
最大得分是 i = 3 且 j = 4 时得到的 |<code>nums[i] - nums[j]</code>| = |8 - 5| = 3 。
最大得分与最小得分之和为 3 。这是最优答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

根据题意我们知道，最小得分实际上是排序数组相邻两个元素的最小差值，最大得分是排序数组首尾元素的差值。数组 $nums$ 的分数是最小得分与最大得分的和。

因此，我们可以先对数组进行排序。由于题目允许我们修改数组中最多两个元素的值，我们可以通过修改一个数，让其跟数组中的另一个数相同，使得最小得分为 $0$，那么数组 $nums$ 的分数实际上就是最大得分。我们可以选择进行如下修改之一：

1. 修改最小的两个数为 $nums[2]$，那么最大得分为 $nums[n - 1] - nums[2]$；
1. 修改最小的一个数为 $nums[1]$，最大的一个数为 $nums[n - 2]$，那么最大得分为 $nums[n - 2] - nums[1]$；
1. 修改最大的两个数为 $nums[n - 3]$，那么最大得分为 $nums[n - 3] - nums[0]$。

最后，我们返回上述三种修改的得分的最小值即可。

时间复杂度 $O(n \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

相似题目：

-   [1509. 三次操作后最大值与最小值的最小差](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1509.Minimum%20Difference%20Between%20Largest%20and%20Smallest%20Value%20in%20Three%20Moves/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        return min(nums[-1] - nums[2], nums[-2] - nums[1], nums[-3] - nums[0])
```

#### Java

```java
class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int a = nums[n - 1] - nums[2];
        int b = nums[n - 2] - nums[1];
        int c = nums[n - 3] - nums[0];
        return Math.min(a, Math.min(b, c));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
    }
};
```

#### Go

```go
func minimizeSum(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	return min(nums[n-1]-nums[2], min(nums[n-2]-nums[1], nums[n-3]-nums[0]))
}
```

#### TypeScript

```ts
function minimizeSum(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    return Math.min(nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]);
}
```

#### Rust

```rust
impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        (nums[n - 1] - nums[2])
            .min(nums[n - 2] - nums[1])
            .min(nums[n - 3] - nums[0])
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minimizeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return min(nums[numsSize - 1] - nums[2], min(nums[numsSize - 2] - nums[1], nums[numsSize - 3] - nums[0]));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2568. 最小无法得到的或值](https://leetcode.cn/problems/minimum-impossible-or){#2568}

{{< tabs "2568" >}}

{{% tab "python" %}}
```python
class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        s = set(nums)
        return next(1 << i for i in range(32) if 1 << i not in s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minImpossibleOR(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int i = 0;; ++i) {
            if (!s.contains(1 << i)) {
                return 1 << i;
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
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0;; ++i) {
            if (!s.count(1 << i)) {
                return 1 << i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minImpossibleOR(nums []int) int {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for i := 0; ; i++ {
		if !s[1<<i] {
			return 1 << i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minImpossibleOR(nums: number[]): number {
    const s: Set<number> = new Set();
    for (const x of nums) {
        s.add(x);
    }
    for (let i = 0; ; ++i) {
        if (!s.has(1 << i)) {
            return 1 << i;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果存在一些整数满足&nbsp;<code>0 &lt;= index<sub>1</sub> &lt; index<sub>2</sub> &lt; ... &lt; index<sub>k</sub> &lt; nums.length</code>&nbsp;，得到&nbsp;<code>nums[index<sub>1</sub>] | nums[index<sub>2</sub>] | ... | nums[index<sub>k</sub>] = x</code>&nbsp;，那么我们说&nbsp;<code>x</code>&nbsp;是&nbsp;<strong>可表达的</strong>&nbsp;。换言之，如果一个整数能由&nbsp;<code>nums</code>&nbsp;的某个子序列的或运算得到，那么它就是可表达的。</p>

<p>请你返回 <code>nums</code>&nbsp;不可表达的 <strong>最小非零整数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,1]
<b>输出：</b>4
<b>解释：</b>1 和 2 已经在数组中，因为 nums[0] | nums[1] = 2 | 1 = 3 ，所以 3 是可表达的。由于 4 是不可表达的，所以我们返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [5,3,2]
<b>输出：</b>1
<b>解释：</b>1 是最小不可表达的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 2 的幂

我们从整数 $1$ 开始考虑，如果 $1$ 是可表达的，那么它必须出现在数组 `nums` 中；如果 $2$ 是可表达的，那么它必须出现在数组 `nums` 中；如果 $1$ 和 $2$ 都是可表达的，那么它们的或运算 $3$ 也是可表达的，以此类推。

因此，我们可以枚举 $2$ 的幂，如果当前枚举的 $2^i$ 不在数组 `nums` 中，那么 $2^i$ 就是不可表达的最小整数。

时间复杂度 $O(n + \log M)$，空间复杂度 $O(n)$。其中 $n$ 和 $M$ 分别是数组 `nums` 的长度和数组 `nums` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        s = set(nums)
        return next(1 << i for i in range(32) if 1 << i not in s)
```

#### Java

```java
class Solution {
    public int minImpossibleOR(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int i = 0;; ++i) {
            if (!s.contains(1 << i)) {
                return 1 << i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0;; ++i) {
            if (!s.count(1 << i)) {
                return 1 << i;
            }
        }
    }
};
```

#### Go

```go
func minImpossibleOR(nums []int) int {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for i := 0; ; i++ {
		if !s[1<<i] {
			return 1 << i
		}
	}
}
```

#### TypeScript

```ts
function minImpossibleOR(nums: number[]): number {
    const s: Set<number> = new Set();
    for (const x of nums) {
        s.add(x);
    }
    for (let i = 0; ; ++i) {
        if (!s.has(1 << i)) {
            return 1 << i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2569. 更新数组后处理求和查询](https://leetcode.cn/problems/handling-sum-queries-after-update){#2569}

{{< tabs "2569" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = self.r = 0
        self.s = self.lazy = 0


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].s = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            self.tr[u].lazy ^= 1
            self.tr[u].s = self.tr[u].r - self.tr[u].l + 1 - self.tr[u].s
            return
        self.pushdown(u)
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if l <= mid:
            self.modify(u << 1, l, r)
        if r > mid:
            self.modify(u << 1 | 1, l, r)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s
        self.pushdown(u)
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        res = 0
        if l <= mid:
            res += self.query(u << 1, l, r)
        if r > mid:
            res += self.query(u << 1 | 1, l, r)
        return res

    def pushup(self, u):
        self.tr[u].s = self.tr[u << 1].s + self.tr[u << 1 | 1].s

    def pushdown(self, u):
        if self.tr[u].lazy:
            mid = (self.tr[u].l + self.tr[u].r) >> 1
            self.tr[u << 1].s = mid - self.tr[u].l + 1 - self.tr[u << 1].s
            self.tr[u << 1].lazy ^= 1
            self.tr[u << 1 | 1].s = self.tr[u].r - mid - self.tr[u << 1 | 1].s
            self.tr[u << 1 | 1].lazy ^= 1
            self.tr[u].lazy ^= 1


class Solution:
    def handleQuery(
        self, nums1: List[int], nums2: List[int], queries: List[List[int]]
    ) -> List[int]:
        tree = SegmentTree(nums1)
        s = sum(nums2)
        ans = []
        for op, a, b in queries:
            if op == 1:
                tree.modify(1, a + 1, b + 1)
            elif op == 2:
                s += a * tree.query(1, 1, len(nums1))
            else:
                ans.append(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l, r;
    int s, lazy;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].s = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy ^= 1;
            tr[u].s = tr[u].r - tr[u].l + 1 - tr[u].s;
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) {
            modify(u << 1, l, r);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 0;
        if (l <= mid) {
            res += query(u << 1, l, r);
        }
        if (r > mid) {
            res += query(u << 1 | 1, l, r);
        }
        return res;
    }

    private void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    private void pushdown(int u) {
        if (tr[u].lazy == 1) {
            int mid = (tr[u].l + tr[u].r) >> 1;
            tr[u << 1].s = mid - tr[u].l + 1 - tr[u << 1].s;
            tr[u << 1].lazy ^= 1;
            tr[u << 1 | 1].s = tr[u].r - mid - tr[u << 1 | 1].s;
            tr[u << 1 | 1].lazy ^= 1;
            tr[u].lazy ^= 1;
        }
    }
}

class Solution {
    public long[] handleQuery(int[] nums1, int[] nums2, int[][] queries) {
        SegmentTree tree = new SegmentTree(nums1);
        long s = 0;
        for (int x : nums2) {
            s += x;
        }
        int m = 0;
        for (var q : queries) {
            if (q[0] == 3) {
                ++m;
            }
        }
        long[] ans = new long[m];
        int i = 0;
        for (var q : queries) {
            if (q[0] == 1) {
                tree.modify(1, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                s += 1L * q[1] * tree.query(1, 1, nums2.length);
            } else {
                ans[i++] = s;
            }
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
    int l = 0, r = 0;
    int s = 0, lazy = 0;
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    void modify(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            tr[u]->lazy ^= 1;
            tr[u]->s = tr[u]->r - tr[u]->l + 1 - tr[u]->s;
            return;
        }
        pushdown(u);
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (l <= mid) {
            modify(u << 1, l, r);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r);
        }
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s;
        }
        pushdown(u);
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int res = 0;
        if (l <= mid) {
            res += query(u << 1, l, r);
        }
        if (r > mid) {
            res += query(u << 1 | 1, l, r);
        }
        return res;
    }

private:
    vector<Node*> tr;
    vector<int> nums;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->s = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->s = tr[u << 1]->s + tr[u << 1 | 1]->s;
    }

    void pushdown(int u) {
        if (tr[u]->lazy) {
            int mid = (tr[u]->l + tr[u]->r) >> 1;
            tr[u << 1]->s = mid - tr[u]->l + 1 - tr[u << 1]->s;
            tr[u << 1]->lazy ^= 1;
            tr[u << 1 | 1]->s = tr[u]->r - mid - tr[u << 1 | 1]->s;
            tr[u << 1 | 1]->lazy ^= 1;
            tr[u]->lazy ^= 1;
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree* tree = new SegmentTree(nums1);
        long long s = 0;
        for (int& x : nums2) {
            s += x;
        }
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                tree->modify(1, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                s += 1LL * q[1] * tree->query(1, 1, nums1.size());
            } else {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type node struct {
	l, r, s, lazy int
}

type segmentTree struct {
	nums []int
	tr   []*node
}

func newSegmentTree(nums []int) *segmentTree {
	n := len(nums)
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{nums, tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].s = t.nums[l-1]
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, l, r int) {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		t.tr[u].lazy ^= 1
		t.tr[u].s = t.tr[u].r - t.tr[u].l + 1 - t.tr[u].s
		return
	}
	t.pushdown(u)
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if l <= mid {
		t.modify(u<<1, l, r)
	}
	if r > mid {
		t.modify(u<<1|1, l, r)
	}
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].s
	}
	t.pushdown(u)
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	res := 0
	if l <= mid {
		res += t.query(u<<1, l, r)
	}
	if r > mid {
		res += t.query(u<<1|1, l, r)
	}
	return res
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].s = t.tr[u<<1].s + t.tr[u<<1|1].s
}

func (t *segmentTree) pushdown(u int) {
	if t.tr[u].lazy == 1 {
		mid := (t.tr[u].l + t.tr[u].r) >> 1
		t.tr[u<<1].s = mid - t.tr[u].l + 1 - t.tr[u<<1].s
		t.tr[u<<1].lazy ^= 1
		t.tr[u<<1|1].s = t.tr[u].r - mid - t.tr[u<<1|1].s
		t.tr[u<<1|1].lazy ^= 1
		t.tr[u].lazy ^= 1
	}
}

func handleQuery(nums1 []int, nums2 []int, queries [][]int) (ans []int64) {
	tree := newSegmentTree(nums1)
	var s int64
	for _, x := range nums2 {
		s += int64(x)
	}
	for _, q := range queries {
		if q[0] == 1 {
			tree.modify(1, q[1]+1, q[2]+1)
		} else if q[0] == 2 {
			s += int64(q[1] * tree.query(1, 1, len(nums1)))
		} else {
			ans = append(ans, s)
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，和一个二维数组&nbsp;<code>queries</code>&nbsp;表示一些操作。总共有 3 种类型的操作：</p>

<ol>
	<li>操作类型 1 为&nbsp;<code>queries[i]&nbsp;= [1, l, r]</code>&nbsp;。你需要将 <code>nums1</code>&nbsp;从下标&nbsp;<code>l</code>&nbsp;到下标 <code>r</code>&nbsp;的所有 <code>0</code>&nbsp;反转成 <code>1</code> 并且所有&nbsp;<code>1</code>&nbsp;反转成 <code>0</code>&nbsp;。<code>l</code>&nbsp;和 <code>r</code>&nbsp;下标都从 <strong>0</strong>&nbsp;开始。</li>
	<li>操作类型 2 为&nbsp;<code>queries[i]&nbsp;= [2, p, 0]</code>&nbsp;。对于&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;中的所有下标，令&nbsp;<code>nums2[i] =&nbsp;nums2[i]&nbsp;+ nums1[i]&nbsp;* p</code>&nbsp;。</li>
	<li>操作类型 3 为&nbsp;<code>queries[i]&nbsp;= [3, 0, 0]</code>&nbsp;。求&nbsp;<code>nums2</code>&nbsp;中所有元素的和。</li>
</ol>

<p>请你返回一个&nbsp;<em>数组</em>，包含&nbsp;<em>所有第三种操作类型&nbsp;</em>的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
<b>输出：</b>[3]
<strong>解释：</strong>第一个操作后 nums1 变为 [1,1,1] 。第二个操作后，nums2 变成 [1,1,1] ，所以第三个操作的答案为 3 。所以返回 [3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
<b>输出：</b>[5]
<b>解释：</b>第一个操作后，nums2 保持不变为 [5] ，所以第二个操作的答案是 5 。所以返回 [5] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length,nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums1.length = nums2.length</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length = 3</code></li>
	<li><code>0 &lt;= l &lt;= r &lt;= nums1.length - 1</code></li>
	<li><code>0 &lt;= p &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= nums1[i] &lt;= 1</code></li>
	<li><code>0 &lt;= nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

根据题目描述：

-   操作 $1$ 是把数组 `nums1` 的下标区间 $[l,..r]$ 的所有数反转，即把 $0$ 变成 $1$，把 $1$ 变成 $0$。
-   操作 $3$ 是求数组 `nums2` 的所有数之和。
-   操作 $2$ 是把数组 `nums2` 的所有数之和加上 $p$ 乘以数组 `nums1` 所有数之和，即 $sum(nums2) = sum(nums2) + p * sum(nums1)$。

因此，我们实际上只需要维护数组 `nums1` 的区间和即可，我们可以通过线段树来实现。

我们定义线段树的每个节点为 `Node`，每个节点包含如下属性：

-   `l`：节点的左端点，下标从 $1$ 开始。
-   `r`：节点的右端点，下标从 $1$ 开始。
-   `s`：节点的区间和。
-   `lazy`：节点的懒标记。

线段树主要有以下几个操作：

-   `build(u, l, r)`：建立线段树。
-   `pushdown(u)`：下传懒标记。
-   `pushup(u)`：用子节点的信息更新父节点的信息。
-   `modify(u, l, r)`：修改区间和，本题中是反转区间中的每个数，那么区间和 $s = r - l + 1 - s$。
-   `query(u, l, r)`：查询区间和。

我们先算出数组 `nums2` 的所有数之和，记为 $s$。

执行操作 $1$ 时，我们只需要调用 `modify(1, l + 1, r + 1)` 即可。

执行操作 $2$ 时，我们更新 $s = s + p \times query(1, 1, n)$ 即可。

执行操作 $3$ 时，我们只需要将 $s$ 加入答案数组即可。

时间复杂度 $O(n + m \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为数组 `nums1` 和 `queries` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self):
        self.l = self.r = 0
        self.s = self.lazy = 0


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].s = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            self.tr[u].lazy ^= 1
            self.tr[u].s = self.tr[u].r - self.tr[u].l + 1 - self.tr[u].s
            return
        self.pushdown(u)
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if l <= mid:
            self.modify(u << 1, l, r)
        if r > mid:
            self.modify(u << 1 | 1, l, r)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s
        self.pushdown(u)
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        res = 0
        if l <= mid:
            res += self.query(u << 1, l, r)
        if r > mid:
            res += self.query(u << 1 | 1, l, r)
        return res

    def pushup(self, u):
        self.tr[u].s = self.tr[u << 1].s + self.tr[u << 1 | 1].s

    def pushdown(self, u):
        if self.tr[u].lazy:
            mid = (self.tr[u].l + self.tr[u].r) >> 1
            self.tr[u << 1].s = mid - self.tr[u].l + 1 - self.tr[u << 1].s
            self.tr[u << 1].lazy ^= 1
            self.tr[u << 1 | 1].s = self.tr[u].r - mid - self.tr[u << 1 | 1].s
            self.tr[u << 1 | 1].lazy ^= 1
            self.tr[u].lazy ^= 1


class Solution:
    def handleQuery(
        self, nums1: List[int], nums2: List[int], queries: List[List[int]]
    ) -> List[int]:
        tree = SegmentTree(nums1)
        s = sum(nums2)
        ans = []
        for op, a, b in queries:
            if op == 1:
                tree.modify(1, a + 1, b + 1)
            elif op == 2:
                s += a * tree.query(1, 1, len(nums1))
            else:
                ans.append(s)
        return ans
```

#### Java

```java
class Node {
    int l, r;
    int s, lazy;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].s = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy ^= 1;
            tr[u].s = tr[u].r - tr[u].l + 1 - tr[u].s;
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) {
            modify(u << 1, l, r);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 0;
        if (l <= mid) {
            res += query(u << 1, l, r);
        }
        if (r > mid) {
            res += query(u << 1 | 1, l, r);
        }
        return res;
    }

    private void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    private void pushdown(int u) {
        if (tr[u].lazy == 1) {
            int mid = (tr[u].l + tr[u].r) >> 1;
            tr[u << 1].s = mid - tr[u].l + 1 - tr[u << 1].s;
            tr[u << 1].lazy ^= 1;
            tr[u << 1 | 1].s = tr[u].r - mid - tr[u << 1 | 1].s;
            tr[u << 1 | 1].lazy ^= 1;
            tr[u].lazy ^= 1;
        }
    }
}

class Solution {
    public long[] handleQuery(int[] nums1, int[] nums2, int[][] queries) {
        SegmentTree tree = new SegmentTree(nums1);
        long s = 0;
        for (int x : nums2) {
            s += x;
        }
        int m = 0;
        for (var q : queries) {
            if (q[0] == 3) {
                ++m;
            }
        }
        long[] ans = new long[m];
        int i = 0;
        for (var q : queries) {
            if (q[0] == 1) {
                tree.modify(1, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                s += 1L * q[1] * tree.query(1, 1, nums2.length);
            } else {
                ans[i++] = s;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    int l = 0, r = 0;
    int s = 0, lazy = 0;
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    void modify(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            tr[u]->lazy ^= 1;
            tr[u]->s = tr[u]->r - tr[u]->l + 1 - tr[u]->s;
            return;
        }
        pushdown(u);
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (l <= mid) {
            modify(u << 1, l, r);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r);
        }
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s;
        }
        pushdown(u);
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int res = 0;
        if (l <= mid) {
            res += query(u << 1, l, r);
        }
        if (r > mid) {
            res += query(u << 1 | 1, l, r);
        }
        return res;
    }

private:
    vector<Node*> tr;
    vector<int> nums;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->s = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->s = tr[u << 1]->s + tr[u << 1 | 1]->s;
    }

    void pushdown(int u) {
        if (tr[u]->lazy) {
            int mid = (tr[u]->l + tr[u]->r) >> 1;
            tr[u << 1]->s = mid - tr[u]->l + 1 - tr[u << 1]->s;
            tr[u << 1]->lazy ^= 1;
            tr[u << 1 | 1]->s = tr[u]->r - mid - tr[u << 1 | 1]->s;
            tr[u << 1 | 1]->lazy ^= 1;
            tr[u]->lazy ^= 1;
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree* tree = new SegmentTree(nums1);
        long long s = 0;
        for (int& x : nums2) {
            s += x;
        }
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                tree->modify(1, q[1] + 1, q[2] + 1);
            } else if (q[0] == 2) {
                s += 1LL * q[1] * tree->query(1, 1, nums1.size());
            } else {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
type node struct {
	l, r, s, lazy int
}

type segmentTree struct {
	nums []int
	tr   []*node
}

func newSegmentTree(nums []int) *segmentTree {
	n := len(nums)
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{nums, tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].s = t.nums[l-1]
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, l, r int) {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		t.tr[u].lazy ^= 1
		t.tr[u].s = t.tr[u].r - t.tr[u].l + 1 - t.tr[u].s
		return
	}
	t.pushdown(u)
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if l <= mid {
		t.modify(u<<1, l, r)
	}
	if r > mid {
		t.modify(u<<1|1, l, r)
	}
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].s
	}
	t.pushdown(u)
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	res := 0
	if l <= mid {
		res += t.query(u<<1, l, r)
	}
	if r > mid {
		res += t.query(u<<1|1, l, r)
	}
	return res
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].s = t.tr[u<<1].s + t.tr[u<<1|1].s
}

func (t *segmentTree) pushdown(u int) {
	if t.tr[u].lazy == 1 {
		mid := (t.tr[u].l + t.tr[u].r) >> 1
		t.tr[u<<1].s = mid - t.tr[u].l + 1 - t.tr[u<<1].s
		t.tr[u<<1].lazy ^= 1
		t.tr[u<<1|1].s = t.tr[u].r - mid - t.tr[u<<1|1].s
		t.tr[u<<1|1].lazy ^= 1
		t.tr[u].lazy ^= 1
	}
}

func handleQuery(nums1 []int, nums2 []int, queries [][]int) (ans []int64) {
	tree := newSegmentTree(nums1)
	var s int64
	for _, x := range nums2 {
		s += int64(x)
	}
	for _, q := range queries {
		if q[0] == 1 {
			tree.modify(1, q[1]+1, q[2]+1)
		} else if q[0] == 2 {
			s += int64(q[1] * tree.query(1, 1, len(nums1)))
		} else {
			ans = append(ans, s)
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
