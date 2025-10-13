---
title: "2830_销售利润最大化"
date: 2025-10-08T18:39:37+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 栈, 滑动窗口, 计数, 贪心]
---

{{< markmap >}}
### [2830_销售利润最大化](#2830)
#### [数组](#2830)
#### [哈希表](#2830)
#### [二分查找](#2830)
#### [动态规划](#2830)
#### [排序](#2830)
### [2831_找出最长等值子数组](#2831)
#### [数组](#2831)
#### [哈希表](#2831)
#### [二分查找](#2831)
#### [滑动窗口](#2831)
### [2832_每个元素为最大值的最大范围 🔒](#2832)
#### [栈](#2832)
#### [数组](#2832)
#### [单调栈](#2832)
### [2833_距离原点最远的点](#2833)
#### [字符串](#2833)
#### [计数](#2833)
### [2834_找出美丽数组的最小和](#2834)
#### [贪心](#2834)
#### [数学](#2834)
### [2835_使子序列的和等于目标的最少操作次数](#2835)
#### [贪心](#2835)
#### [位运算](#2835)
#### [数组](#2835)
### [2836_在传球游戏中最大化函数值](#2836)
#### [位运算](#2836)
#### [数组](#2836)
#### [动态规划](#2836)
### [2837_总旅行距离 🔒](#2837)
#### [数据库](#2837)
### [2838_英雄可以获得的最大金币数 🔒](#2838)
#### [数组](#2838)
#### [双指针](#2838)
#### [二分查找](#2838)
#### [前缀和](#2838)
#### [排序](#2838)
### [2839_判断通过操作能否让字符串相等 I](#2839)
#### [字符串](#2839)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2830_销售利润最大化
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 2831_找出最长等值子数组
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 滑动窗口
---
### 2832_每个元素为最大值的最大范围 🔒
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 2833_距离原点最远的点
___
#### 字符串
___
#### 计数
---
### 2834_找出美丽数组的最小和
___
#### 贪心
___
#### 数学
---
### 2835_使子序列的和等于目标的最少操作次数
___
#### 贪心
___
#### 位运算
___
#### 数组
---
### 2836_在传球游戏中最大化函数值
___
#### 位运算
___
#### 数组
___
#### 动态规划
---
### 2837_总旅行距离 🔒
___
#### 数据库
---
### 2838_英雄可以获得的最大金币数 🔒
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 前缀和
___
#### 排序
---
### 2839_判断通过操作能否让字符串相等 I
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 滑动窗口 | 计数 |
| 贪心 |  |  |

# [2830. 销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman){#2830}

{{< tabs "2830" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
        offers.sort(key=lambda x: x[1])
        f = [0] * (len(offers) + 1)
        g = [x[1] for x in offers]
        for i, (s, _, v) in enumerate(offers, 1):
            j = bisect_left(g, s)
            f[i] = max(f[i - 1], f[j] + v)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeTheProfit(int n, List<List<Integer>> offers) {
        offers.sort((a, b) -> a.get(1) - b.get(1));
        n = offers.size();
        int[] f = new int[n + 1];
        int[] g = new int[n];
        for (int i = 0; i < n; ++i) {
            g[i] = offers.get(i).get(1);
        }
        for (int i = 1; i <= n; ++i) {
            var o = offers.get(i - 1);
            int j = search(g, o.get(0));
            f[i] = Math.max(f[i - 1], f[j] + o.get(2));
        }
        return f[n];
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
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        n = offers.size();
        vector<int> f(n + 1);
        vector<int> g;
        for (auto& o : offers) {
            g.push_back(o[1]);
        }
        for (int i = 1; i <= n; ++i) {
            auto o = offers[i - 1];
            int j = lower_bound(g.begin(), g.end(), o[0]) - g.begin();
            f[i] = max(f[i - 1], f[j] + o[2]);
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeTheProfit(n int, offers [][]int) int {
	sort.Slice(offers, func(i, j int) bool { return offers[i][1] < offers[j][1] })
	n = len(offers)
	f := make([]int, n+1)
	g := []int{}
	for _, o := range offers {
		g = append(g, o[1])
	}
	for i := 1; i <= n; i++ {
		j := sort.SearchInts(g, offers[i-1][0])
		f[i] = max(f[i-1], f[j]+offers[i-1][2])
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeTheProfit(n: number, offers: number[][]): number {
    offers.sort((a, b) => a[1] - b[1]);
    n = offers.length;
    const f: number[] = Array(n + 1).fill(0);
    const g = offers.map(x => x[1]);
    const search = (x: number) => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (g[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        const j = search(offers[i - 1][0]);
        f[i] = Math.max(f[i - 1], f[j] + offers[i - 1][2]);
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> 表示数轴上的房屋数量，编号从 <code>0</code> 到 <code>n - 1</code> 。</p>

<p>另给你一个二维整数数组 <code>offers</code> ，其中 <code>offers[i] = [start<sub>i</sub>, end<sub>i</sub>, gold<sub>i</sub>]</code> 表示第 <code>i</code> 个买家想要以 <code>gold<sub>i</sub></code> 枚金币的价格购买从 <code>start<sub>i</sub></code> 到 <code>end<sub>i</sub></code> 的所有房屋。</p>

<p>作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。</p>

<p>返回你可以赚取的金币的最大数目。</p>

<p><strong>注意</strong> 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
<strong>输出：</strong>3
<strong>解释：</strong>
有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,0] 范围内的房屋以 1 金币的价格出售给第 1 位买家，并将位于 [1,3] 范围内的房屋以 2 金币的价格出售给第 3 位买家。
可以证明我们最多只能获得 3 枚金币。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
<strong>输出：</strong>10
<strong>解释：</strong>有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,2] 范围内的房屋以 10 金币的价格出售给第 2 位买家。
可以证明我们最多只能获得 10 枚金币。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= offers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>offers[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= gold<sub>i</sub> &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找 + 动态规划

我们将所有的购买要约按照 $end$ 从小到大排序，然后使用动态规划求解。

定义 $f[i]$ 表示前 $i$ 个购买要约中，我们可以获得的最大金币数。答案即为 $f[n]$。

对于 $f[i]$，我们可以选择不卖出第 $i$ 个购买要约，此时 $f[i] = f[i - 1]$；也可以选择卖出第 $i$ 个购买要约，此时 $f[i] = f[j] + gold_i$，其中 $j$ 是满足 $end_j \leq start_i$ 的最大下标。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是购买要约的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
        offers.sort(key=lambda x: x[1])
        f = [0] * (len(offers) + 1)
        g = [x[1] for x in offers]
        for i, (s, _, v) in enumerate(offers, 1):
            j = bisect_left(g, s)
            f[i] = max(f[i - 1], f[j] + v)
        return f[-1]
```

#### Java

```java
class Solution {
    public int maximizeTheProfit(int n, List<List<Integer>> offers) {
        offers.sort((a, b) -> a.get(1) - b.get(1));
        n = offers.size();
        int[] f = new int[n + 1];
        int[] g = new int[n];
        for (int i = 0; i < n; ++i) {
            g[i] = offers.get(i).get(1);
        }
        for (int i = 1; i <= n; ++i) {
            var o = offers.get(i - 1);
            int j = search(g, o.get(0));
            f[i] = Math.max(f[i - 1], f[j] + o.get(2));
        }
        return f[n];
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
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        n = offers.size();
        vector<int> f(n + 1);
        vector<int> g;
        for (auto& o : offers) {
            g.push_back(o[1]);
        }
        for (int i = 1; i <= n; ++i) {
            auto o = offers[i - 1];
            int j = lower_bound(g.begin(), g.end(), o[0]) - g.begin();
            f[i] = max(f[i - 1], f[j] + o[2]);
        }
        return f[n];
    }
};
```

#### Go

```go
func maximizeTheProfit(n int, offers [][]int) int {
	sort.Slice(offers, func(i, j int) bool { return offers[i][1] < offers[j][1] })
	n = len(offers)
	f := make([]int, n+1)
	g := []int{}
	for _, o := range offers {
		g = append(g, o[1])
	}
	for i := 1; i <= n; i++ {
		j := sort.SearchInts(g, offers[i-1][0])
		f[i] = max(f[i-1], f[j]+offers[i-1][2])
	}
	return f[n]
}
```

#### TypeScript

```ts
function maximizeTheProfit(n: number, offers: number[][]): number {
    offers.sort((a, b) => a[1] - b[1]);
    n = offers.length;
    const f: number[] = Array(n + 1).fill(0);
    const g = offers.map(x => x[1]);
    const search = (x: number) => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (g[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        const j = search(offers[i - 1][0]);
        f[i] = Math.max(f[i - 1], f[j] + offers[i - 1][2]);
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2831. 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray){#2831}

{{< tabs "2831" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        g = defaultdict(list)
        for i, x in enumerate(nums):
            g[x].append(i)
        ans = 0
        for ids in g.values():
            l = 0
            for r in range(len(ids)):
                while ids[r] - ids[l] - (r - l) > k:
                    l += 1
                ans = max(ans, r - l + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        int n = nums.size();
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[nums.get(i)].add(i);
        }
        int ans = 0;
        for (List<Integer> ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids.get(r) - ids.get(l) - (r - l) > k) {
                    ++l;
                }
                ans = Math.max(ans, r - l + 1);
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> g[n + 1];
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        int ans = 0;
        for (const auto& ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids[r] - ids[l] - (r - l) > k) {
                    ++l;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestEqualSubarray(nums []int, k int) (ans int) {
	g := make([][]int, len(nums)+1)
	for i, x := range nums {
		g[x] = append(g[x], i)
	}
	for _, ids := range g {
		l := 0
		for r := range ids {
			for ids[r]-ids[l]-(r-l) > k {
				l++
			}
			ans = max(ans, r-l+1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestEqualSubarray(nums: number[], k: number): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);
    for (let i = 0; i < n; ++i) {
        g[nums[i]].push(i);
    }
    let ans = 0;
    for (const ids of g) {
        let l = 0;
        for (let r = 0; r < ids.length; ++r) {
            while (ids[r] - ids[l] - (r - l) > k) {
                ++l;
            }
            ans = Math.max(ans, r - l + 1);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>如果子数组中所有元素都相等，则认为子数组是一个 <strong>等值子数组</strong> 。注意，空数组是 <strong>等值子数组</strong> 。</p>

<p>从 <code>nums</code> 中删除最多 <code>k</code> 个元素后，返回可能的最长等值子数组的长度。</p>

<p><strong>子数组</strong> 是数组中一个连续且可能为空的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,3,1,3], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>最优的方案是删除下标 2 和下标 4 的元素。
删除后，nums 等于 [1, 3, 3, 3] 。
最长等值子数组从 i = 1 开始到 j = 3 结束，长度等于 3 。
可以证明无法创建更长的等值子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,2,1,1], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>最优的方案是删除下标 2 和下标 3 的元素。 
删除后，nums 等于 [1, 1, 1, 1] 。 
数组自身就是等值子数组，长度等于 4 。 
可以证明无法创建更长的等值子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

我们用双指针维护一个单调变长的窗口，用哈希表维护窗口中每个元素出现的次数。

窗口中的所有元素个数减去窗口中出现次数最多的元素个数，就是窗口中需要删除的元素个数。

每一次，我们将右指针指向的元素加入窗口，然后更新哈希表，同时更新窗口中出现次数最多的元素个数。当窗口中需要删除的元素个数超过了 $k$ 时，我们就移动一次左指针，然后更新哈希表。

遍历结束后，返回出现次数最多的元素个数即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        l = 0
        mx = 0
        for r, x in enumerate(nums):
            cnt[x] += 1
            mx = max(mx, cnt[x])
            if r - l + 1 - mx > k:
                cnt[nums[l]] -= 1
                l += 1
        return mx
```

#### Java

```java
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int mx = 0, l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            cnt.merge(nums.get(r), 1, Integer::sum);
            mx = Math.max(mx, cnt.get(nums.get(r)));
            if (r - l + 1 - mx > k) {
                cnt.merge(nums.get(l++), -1, Integer::sum);
            }
        }
        return mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int mx = 0, l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            mx = max(mx, ++cnt[nums[r]]);
            if (r - l + 1 - mx > k) {
                --cnt[nums[l++]];
            }
        }
        return mx;
    }
};
```

#### Go

```go
func longestEqualSubarray(nums []int, k int) int {
	cnt := map[int]int{}
	mx, l := 0, 0
	for r, x := range nums {
		cnt[x]++
		mx = max(mx, cnt[x])
		if r-l+1-mx > k {
			cnt[nums[l]]--
			l++
		}
	}
	return mx
}
```

#### TypeScript

```ts
function longestEqualSubarray(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    let mx = 0;
    let l = 0;
    for (let r = 0; r < nums.length; ++r) {
        cnt.set(nums[r], (cnt.get(nums[r]) ?? 0) + 1);
        mx = Math.max(mx, cnt.get(nums[r])!);
        if (r - l + 1 - mx > k) {
            cnt.set(nums[l], cnt.get(nums[l])! - 1);
            ++l;
        }
    }
    return mx;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 双指针（写法二）

我们可以用一个哈希表 $g$ 维护每个元素的下标列表。

接下来，我们枚举每个元素作为等值元素，我们从哈希表 $g$ 中取出这个元素的下标列表 $ids$，然后我们定义两个指针 $l$ 和 $r$，用于维护一个窗口，使得窗口内的元素个数减去等值元素的个数，结果不超过 $k$。那么我们只需要求出最大的满足条件的窗口即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        g = defaultdict(list)
        for i, x in enumerate(nums):
            g[x].append(i)
        ans = 0
        for ids in g.values():
            l = 0
            for r in range(len(ids)):
                while ids[r] - ids[l] - (r - l) > k:
                    l += 1
                ans = max(ans, r - l + 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        int n = nums.size();
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[nums.get(i)].add(i);
        }
        int ans = 0;
        for (List<Integer> ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids.get(r) - ids.get(l) - (r - l) > k) {
                    ++l;
                }
                ans = Math.max(ans, r - l + 1);
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> g[n + 1];
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        int ans = 0;
        for (const auto& ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids[r] - ids[l] - (r - l) > k) {
                    ++l;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestEqualSubarray(nums []int, k int) (ans int) {
	g := make([][]int, len(nums)+1)
	for i, x := range nums {
		g[x] = append(g[x], i)
	}
	for _, ids := range g {
		l := 0
		for r := range ids {
			for ids[r]-ids[l]-(r-l) > k {
				l++
			}
			ans = max(ans, r-l+1)
		}
	}
	return
}
```

#### TypeScript

```ts
function longestEqualSubarray(nums: number[], k: number): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);
    for (let i = 0; i < n; ++i) {
        g[nums[i]].push(i);
    }
    let ans = 0;
    for (const ids of g) {
        let l = 0;
        for (let r = 0; r < ids.length; ++r) {
            while (ids[r] - ids[l] - (r - l) > k) {
                ++l;
            }
            ans = Math.max(ans, r - l + 1);
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

# [2832. 每个元素为最大值的最大范围 🔒](https://leetcode.cn/problems/maximal-range-that-each-element-is-maximum-in-it){#2832}

{{< tabs "2832" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLengthOfRanges(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] <= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        return [r - l - 1 for l, r in zip(left, right)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maximumLengthOfRanges(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = right[i] - left[i] - 1;
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
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = right[i] - left[i] - 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLengthOfRanges(nums []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = right[i] - left[i] - 1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLengthOfRanges(nums: number[]): number[] {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)] <= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk.at(-1)] <= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    return left.map((l, i) => right[i] - l - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个由 <strong>不同</strong> 整数构成的 <strong>0</strong> 索引数组 <code>nums</code> 。</p>

<p>我们用以下方式定义与 <code>nums</code> 长度相同的 <strong>0</strong> 索引数组 <code>ans</code> ：</p>

<ul>
	<li><code>ans[i]</code> 是子数组 <code>nums[l..r]</code> 的 <strong>最大</strong> 长度，该子数组中的最大元素等于 <code>nums[i]</code> 。</li>
</ul>

<p>返回数组 <code>ans</code> 。</p>

<p><strong>注意</strong>，<strong>子数组</strong> 是数组的连续部分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,5,4,3,6]
<b>输出：</b>[1,4,2,1,5]
<b>解释：</b>对于 nums[0]，最长的子数组，其中最大值为 1，是 nums[0..0]，所以 ans[0] = 1。 
对于 nums[1]，最长的子数组，是 nums[0..3]，其中最大值为 5，所以 ans[1] = 4。 
对于 nums[2]，最长的子数组，是 nums[2..3]，其中最大值为 4，所以 ans[2] = 2。 
对于 nums[3]，最长的子数组，是 nums[3..3]，其中最大值为 3，所以 ans[3] = 1。 
对于 nums[4]，最长的子数组，是 nums[0..4]，其中最大值为 6，所以 ans[4] = 5。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>[1,2,3,4,5]
<b>解释：</b>对于 nums[i]，最长的子数组，是 nums[0..i]，其中最大值与 nums[i] 相等，所以 ans[i] = i + 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>所有&nbsp;<code>nums</code> 中的元素都是不重复的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

本题属于单调栈的模板题，我们只需要利用单调栈，求出每个元素 $nums[i]$ 左边和右边第一个比它大的元素的位置，分别记为 $left[i]$ 和 $right[i]$，那么 $nums[i]$ 作为最大值的区间长度就是 $right[i] - left[i] - 1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLengthOfRanges(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] <= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        return [r - l - 1 for l, r in zip(left, right)]
```

#### Java

```java
class Solution {
    public int[] maximumLengthOfRanges(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = right[i] - left[i] - 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = right[i] - left[i] - 1;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLengthOfRanges(nums []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = right[i] - left[i] - 1
	}
	return ans
}
```

#### TypeScript

```ts
function maximumLengthOfRanges(nums: number[]): number[] {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)] <= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk.at(-1)] <= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    return left.map((l, i) => right[i] - l - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2833. 距离原点最远的点](https://leetcode.cn/problems/furthest-point-from-origin){#2833}

{{< tabs "2833" >}}

{{% tab "python" %}}
```python
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return abs(moves.count("L") - moves.count("R")) + moves.count("_")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        return Math.abs(count(moves, 'L') - count(moves, 'R')) + count(moves, '_');
    }

    private int count(String s, char c) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == c) {
                ++cnt;
            }
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
    int furthestDistanceFromOrigin(string moves) {
        auto cnt = [&](char c) {
            return count(moves.begin(), moves.end(), c);
        };
        return abs(cnt('L') - cnt('R')) + cnt('_');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func furthestDistanceFromOrigin(moves string) int {
	count := func(c string) int { return strings.Count(moves, c) }
	return abs(count("L")-count("R")) + count("_")
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
function furthestDistanceFromOrigin(moves: string): number {
    const count = (c: string) => moves.split('').filter(x => x === c).length;
    return Math.abs(count('L') - count('R')) + count('_');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的字符串 <code>moves</code> ，该字符串仅由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成。字符串表示你在一条原点为 <code>0</code> 的数轴上的若干次移动。</p>

<p>你的初始位置就在原点（<code>0</code>），第 <code>i</code> 次移动过程中，你可以根据对应字符选择移动方向：</p>

<ul>
	<li>如果 <code>moves[i] = 'L'</code> 或 <code>moves[i] = '_'</code> ，可以选择向左移动一个单位距离</li>
	<li>如果 <code>moves[i] = 'R'</code> 或 <code>moves[i] = '_'</code> ，可以选择向右移动一个单位距离</li>
</ul>

<p>移动 <code>n</code> 次之后，请你找出可以到达的距离原点 <strong>最远</strong> 的点，并返回 <strong>从原点到这一点的距离</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>moves = "L_RL__R"
<strong>输出：</strong>3
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -3 ，移动的序列为 "LLRLLLR" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>moves = "_R__LL_"
<strong>输出：</strong>5
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -5 ，移动的序列为 "LRLLLLL" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>moves = "_______"
<strong>输出：</strong>7
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 7 ，移动的序列为 "RRRRRRR" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= moves.length == n &lt;= 50</code></li>
	<li><code>moves</code> 仅由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

遇到字符 `'_'` 时，我们可以选择向左或向右移动，而题目需要我们求出离原点最远的点，因此，我们可以先进行一次遍历，贪心地把所有的 `'_'` 都移到左边，求出此时离原点最远的点，再进行一次遍历，贪心地把所有的 `'_'` 都移到右边，求出此时离原点最远的点，最后取两次遍历中的最大值即可。

进一步地，我们只需要统计出字符串中 `'L'`、`'R'` 的个数之差，再加上 `'_'` 的个数即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return abs(moves.count("L") - moves.count("R")) + moves.count("_")
```

#### Java

```java
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        return Math.abs(count(moves, 'L') - count(moves, 'R')) + count(moves, '_');
    }

    private int count(String s, char c) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == c) {
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
    int furthestDistanceFromOrigin(string moves) {
        auto cnt = [&](char c) {
            return count(moves.begin(), moves.end(), c);
        };
        return abs(cnt('L') - cnt('R')) + cnt('_');
    }
};
```

#### Go

```go
func furthestDistanceFromOrigin(moves string) int {
	count := func(c string) int { return strings.Count(moves, c) }
	return abs(count("L")-count("R")) + count("_")
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
function furthestDistanceFromOrigin(moves: string): number {
    const count = (c: string) => moves.split('').filter(x => x === c).length;
    return Math.abs(count('L') - count('R')) + count('_');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2834. 找出美丽数组的最小和](https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array){#2834}

{{< tabs "2834" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        mod = 10**9 + 7
        m = target // 2
        if n <= m:
            return ((1 + n) * n // 2) % mod
        return ((1 + m) * m // 2 + (target + target + n - m - 1) * (n - m) // 2) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumPossibleSum(int n, int target) {
        final int mod = (int) 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (int) ((1L + n) * n / 2 % mod);
        }
        long a = (1L + m) * m / 2 % mod;
        long b = ((1L * target + target + n - m - 1) * (n - m) / 2) % mod;
        return (int) ((a + b) % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (1LL + n) * n / 2 % mod;
        }
        long long a = (1LL + m) * m / 2 % mod;
        long long b = (1LL * target + target + n - m - 1) * (n - m) / 2 % mod;
        return (a + b) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumPossibleSum(n int, target int) int {
	const mod int = 1e9 + 7
	m := target / 2
	if n <= m {
		return (n + 1) * n / 2 % mod
	}
	a := (m + 1) * m / 2 % mod
	b := (target + target + n - m - 1) * (n - m) / 2 % mod
	return (a + b) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumPossibleSum(n: number, target: number): number {
    const mod = 10 ** 9 + 7;
    const m = target >> 1;
    if (n <= m) {
        return (((1 + n) * n) / 2) % mod;
    }
    return (((1 + m) * m) / 2 + ((target + target + n - m - 1) * (n - m)) / 2) % mod;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimumPossibleSum(int n, int target) {
        const int mod = (int) 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (int) ((1L + n) * n / 2 % mod);
        }
        long a = (1L + m) * m / 2 % mod;
        long b = ((1L * target + target + n - m - 1) * (n - m) / 2) % mod;
        return (int) ((a + b) % mod);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数：<code>n</code> 和 <code>target</code> 。</p>

<p>如果数组 <code>nums</code> 满足下述条件，则称其为 <strong>美丽数组</strong> 。</p>

<ul>
	<li><code>nums.length == n</code>.</li>
	<li><code>nums</code> 由两两互不相同的正整数组成。</li>
	<li>在范围 <code>[0, n-1]</code> 内，<strong>不存在 </strong>两个 <strong>不同</strong> 下标 <code>i</code> 和 <code>j</code> ，使得 <code>nums[i] + nums[j] == target</code> 。</li>
</ul>

<p>返回符合条件的美丽数组所可能具备的 <strong>最小</strong> 和，并对结果进行取模 <code>10<sup>9</sup>&nbsp;+ 7</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, target = 3
<strong>输出：</strong>4
<strong>解释：</strong>nums = [1,3] 是美丽数组。
- nums 的长度为 n = 2 。
- nums 由两两互不相同的正整数组成。
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 4 是符合条件的美丽数组所可能具备的最小和。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, target = 3
<strong>输出：</strong>8
<strong>解释：</strong>
nums = [1,3,4] 是美丽数组。 
- nums 的长度为 n = 3 。 
- nums 由两两互不相同的正整数组成。 
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 8 是符合条件的美丽数组所可能具备的最小和。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1, target = 1
<strong>输出：</strong>1
<strong>解释：</strong>nums = [1] 是美丽数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 数学

我们可以贪心地从 $x = 1$ 开始构造数组 $nums$，每次选择 $x$，并且排除 $target - x$。

我们不妨记 $m = \left\lfloor \frac{target}{2} \right\rfloor$。

如果 $x <= m$，那么我们可以选择的数有 $1, 2, \cdots, n$，所以数组的和为 $\left\lfloor \frac{(1+n)n}{2} \right\rfloor$。

如果 $x > m$，那么我们可以选择的数有 $1, 2, \cdots, m$，共 $m$ 个数，以及 $n - m$ 个从 $target$ 开始的数，所以数组的和为 $\left\lfloor \frac{(1+m)m}{2} \right\rfloor + \left\lfloor \frac{(target + target + n - m - 1)(n-m)}{2} \right\rfloor$。

注意，我们需要对结果取模 $10^9 + 7$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        mod = 10**9 + 7
        m = target // 2
        if n <= m:
            return ((1 + n) * n // 2) % mod
        return ((1 + m) * m // 2 + (target + target + n - m - 1) * (n - m) // 2) % mod
```

#### Java

```java
class Solution {
    public int minimumPossibleSum(int n, int target) {
        final int mod = (int) 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (int) ((1L + n) * n / 2 % mod);
        }
        long a = (1L + m) * m / 2 % mod;
        long b = ((1L * target + target + n - m - 1) * (n - m) / 2) % mod;
        return (int) ((a + b) % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (1LL + n) * n / 2 % mod;
        }
        long long a = (1LL + m) * m / 2 % mod;
        long long b = (1LL * target + target + n - m - 1) * (n - m) / 2 % mod;
        return (a + b) % mod;
    }
};
```

#### Go

```go
func minimumPossibleSum(n int, target int) int {
	const mod int = 1e9 + 7
	m := target / 2
	if n <= m {
		return (n + 1) * n / 2 % mod
	}
	a := (m + 1) * m / 2 % mod
	b := (target + target + n - m - 1) * (n - m) / 2 % mod
	return (a + b) % mod
}
```

#### TypeScript

```ts
function minimumPossibleSum(n: number, target: number): number {
    const mod = 10 ** 9 + 7;
    const m = target >> 1;
    if (n <= m) {
        return (((1 + n) * n) / 2) % mod;
    }
    return (((1 + m) * m) / 2 + ((target + target + n - m - 1) * (n - m)) / 2) % mod;
}
```

#### C#

```cs
public class Solution {
    public int MinimumPossibleSum(int n, int target) {
        const int mod = (int) 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (int) ((1L + n) * n / 2 % mod);
        }
        long a = (1L + m) * m / 2 % mod;
        long b = ((1L * target + target + n - m - 1) * (n - m) / 2) % mod;
        return (int) ((a + b) % mod);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2835. 使子序列的和等于目标的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum){#2835}

{{< tabs "2835" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target:
            return -1
        cnt = [0] * 32
        for x in nums:
            for i in range(32):
                if x >> i & 1:
                    cnt[i] += 1
        i = j = 0
        ans = 0
        while 1:
            while i < 32 and (target >> i & 1) == 0:
                i += 1
            if i == 32:
                break
            while j < i:
                cnt[j + 1] += cnt[j] // 2
                cnt[j] %= 2
                j += 1
            while cnt[j] == 0:
                cnt[j] = 1
                j += 1
            ans += j - i
            cnt[j] -= 1
            j = i
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(List<Integer> nums, int target) {
        long s = 0;
        int[] cnt = new int[32];
        for (int x : nums) {
            s += x;
            for (int i = 0; i < 32; ++i) {
                if ((x >> i & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        if (s < target) {
            return -1;
        }
        int i = 0, j = 0;
        int ans = 0;
        while (true) {
            while (i < 32 && (target >> i & 1) == 0) {
                ++i;
            }
            if (i == 32) {
                return ans;
            }
            while (j < i) {
                cnt[j + 1] += cnt[j] / 2;
                cnt[j] %= 2;
                ++j;
            }
            while (cnt[j] == 0) {
                cnt[j] = 1;
                ++j;
            }
            ans += j - i;
            --cnt[j];
            j = i;
            ++i;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long s = 0;
        int cnt[32]{};
        for (int x : nums) {
            s += x;
            for (int i = 0; i < 32; ++i) {
                if (x >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        if (s < target) {
            return -1;
        }
        int i = 0, j = 0;
        int ans = 0;
        while (1) {
            while (i < 32 && (target >> i & 1) == 0) {
                ++i;
            }
            if (i == 32) {
                return ans;
            }
            while (j < i) {
                cnt[j + 1] += cnt[j] / 2;
                cnt[j] %= 2;
                ++j;
            }
            while (cnt[j] == 0) {
                cnt[j] = 1;
                ++j;
            }
            ans += j - i;
            --cnt[j];
            j = i;
            ++i;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, target int) (ans int) {
	s := 0
	cnt := [32]int{}
	for _, x := range nums {
		s += x
		for i := 0; i < 32; i++ {
			if x>>i&1 > 0 {
				cnt[i]++
			}
		}
	}
	if s < target {
		return -1
	}
	var i, j int
	for {
		for i < 32 && target>>i&1 == 0 {
			i++
		}
		if i == 32 {
			return
		}
		for j < i {
			cnt[j+1] += cnt[j] >> 1
			cnt[j] %= 2
			j++
		}
		for cnt[j] == 0 {
			cnt[j] = 1
			j++
		}
		ans += j - i
		cnt[j]--
		j = i
		i++
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], target: number): number {
    let s = 0;
    const cnt: number[] = Array(32).fill(0);
    for (const x of nums) {
        s += x;
        for (let i = 0; i < 32; ++i) {
            if ((x >> i) & 1) {
                ++cnt[i];
            }
        }
    }
    if (s < target) {
        return -1;
    }
    let [ans, i, j] = [0, 0, 0];
    while (1) {
        while (i < 32 && ((target >> i) & 1) === 0) {
            ++i;
        }
        if (i === 32) {
            return ans;
        }
        while (j < i) {
            cnt[j + 1] += cnt[j] >> 1;
            cnt[j] %= 2;
            ++j;
        }
        while (cnt[j] == 0) {
            cnt[j] = 1;
            j++;
        }
        ans += j - i;
        cnt[j]--;
        j = i;
        i++;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，它包含 <strong>非负</strong>&nbsp;整数，且全部为 <code>2</code>&nbsp;的幂，同时给你一个整数&nbsp;<code>target</code>&nbsp;。</p>

<p>一次操作中，你必须对数组做以下修改：</p>

<ul>
	<li>选择数组中一个元素&nbsp;<code>nums[i]</code>&nbsp;，满足&nbsp;<code>nums[i] &gt; 1</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[i]</code>&nbsp;从数组中删除。</li>
	<li>在 <code>nums</code>&nbsp;的 <strong>末尾</strong>&nbsp;添加 <strong>两个</strong>&nbsp;数，值都为&nbsp;<code>nums[i] / 2</code>&nbsp;。</li>
</ul>

<p>你的目标是让 <code>nums</code>&nbsp;的一个 <strong>子序列</strong>&nbsp;的元素和等于&nbsp;<code>target</code>&nbsp;，请你返回达成这一目标的 <strong>最少操作次数</strong>&nbsp;。如果无法得到这样的子序列，请你返回 <code>-1</code>&nbsp;。</p>

<p>数组中一个 <strong>子序列</strong>&nbsp;是通过删除原数组中一些元素，并且不改变剩余元素顺序得到的剩余数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,8], target = 7
<b>输出：</b>1
<b>解释：</b>第一次操作中，我们选择元素 nums[2] 。数组变为 nums = [1,2,4,4] 。
这时候，nums 包含子序列 [1,2,4] ，和为 7 。
无法通过更少的操作得到和为 7 的子序列。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,32,1,2], target = 12
<b>输出：</b>2
<b>解释：</b>第一次操作中，我们选择元素 nums[1] 。数组变为 nums = [1,1,2,16,16] 。
第二次操作中，我们选择元素 nums[3] 。数组变为 nums = [1,1,2,16,8,8] 。
这时候，nums 包含子序列 [1,1,2,8] ，和为 12 。
无法通过更少的操作得到和为 12 的子序列。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,32,1], target = 35
<b>输出：</b>-1
<b>解释：</b>无法得到和为 35 的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2<sup>30</sup></code></li>
	<li><code>nums</code>&nbsp;只包含非负整数，且均为 2 的幂。</li>
	<li><code>1 &lt;= target &lt; 2<sup>31</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

观察题目中的操作，我们发现，每次操作实际上是把一个大于 $1$ 的数拆分为两个相等的数，这意味着操作后数组的元素和不会发生变化。因此，如果数组的元素和 $s$ 小于 $target$，则无法通过题目描述的操作得到和为 $target$ 的子序列，直接返回 $-1$ 即可。否则，我们一定可以通过拆分操作，使得数组某个子序列的元素和等于 $target$。

另外，拆分操作实际上会把二进制高位为 $1$ 的数置为 $0$，并把低一位的数加上 $2$。因此，我们先用一个长度为 $32$ 的数组记录数组 $nums$ 所有元素的二进制表示中每个二进制位上 $1$ 的出现次数。

接下来，从 $target$ 的低位开始遍历，对于 $target$ 的第 $i$ 位，如果当前位数字为 $0$，则直接跳过，即 $i = i + 1$。如果当前位数字为 $1$，我们需要在数组 $cnt$ 中，找到最小的数字 $j$（其中 $j \ge i$），使得 $cnt[j] \gt 0$，然后我们将该位的数字 $1$ 往低位 $i$ 拆分，即把 $cnt[j]$ 减 $1$，而 $cnt[i..j-1]$ 的每一位置为 $1$，操作次数为 $j-i$。接下来，我们令 $j = i$，然后 $i = i + 1$。重复上述操作，直到 $i$ 超出数组 $cnt$ 的下标范围，返回此时的操作次数。

注意，如果 $j \lt i$，实际上两个低位的 $1$ 可以合并成一个高一位的 $1$。因此，如果 $j \lt i$，我们将 $\frac{cnt[j]}{2}$ 加到 $cnt[j+1]$ 中，并将 $cnt[j]$ 取模 $2$，然后令 $j = j + 1$，继续上述操作。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target:
            return -1
        cnt = [0] * 32
        for x in nums:
            for i in range(32):
                if x >> i & 1:
                    cnt[i] += 1
        i = j = 0
        ans = 0
        while 1:
            while i < 32 and (target >> i & 1) == 0:
                i += 1
            if i == 32:
                break
            while j < i:
                cnt[j + 1] += cnt[j] // 2
                cnt[j] %= 2
                j += 1
            while cnt[j] == 0:
                cnt[j] = 1
                j += 1
            ans += j - i
            cnt[j] -= 1
            j = i
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(List<Integer> nums, int target) {
        long s = 0;
        int[] cnt = new int[32];
        for (int x : nums) {
            s += x;
            for (int i = 0; i < 32; ++i) {
                if ((x >> i & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        if (s < target) {
            return -1;
        }
        int i = 0, j = 0;
        int ans = 0;
        while (true) {
            while (i < 32 && (target >> i & 1) == 0) {
                ++i;
            }
            if (i == 32) {
                return ans;
            }
            while (j < i) {
                cnt[j + 1] += cnt[j] / 2;
                cnt[j] %= 2;
                ++j;
            }
            while (cnt[j] == 0) {
                cnt[j] = 1;
                ++j;
            }
            ans += j - i;
            --cnt[j];
            j = i;
            ++i;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long s = 0;
        int cnt[32]{};
        for (int x : nums) {
            s += x;
            for (int i = 0; i < 32; ++i) {
                if (x >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        if (s < target) {
            return -1;
        }
        int i = 0, j = 0;
        int ans = 0;
        while (1) {
            while (i < 32 && (target >> i & 1) == 0) {
                ++i;
            }
            if (i == 32) {
                return ans;
            }
            while (j < i) {
                cnt[j + 1] += cnt[j] / 2;
                cnt[j] %= 2;
                ++j;
            }
            while (cnt[j] == 0) {
                cnt[j] = 1;
                ++j;
            }
            ans += j - i;
            --cnt[j];
            j = i;
            ++i;
        }
    }
};
```

#### Go

```go
func minOperations(nums []int, target int) (ans int) {
	s := 0
	cnt := [32]int{}
	for _, x := range nums {
		s += x
		for i := 0; i < 32; i++ {
			if x>>i&1 > 0 {
				cnt[i]++
			}
		}
	}
	if s < target {
		return -1
	}
	var i, j int
	for {
		for i < 32 && target>>i&1 == 0 {
			i++
		}
		if i == 32 {
			return
		}
		for j < i {
			cnt[j+1] += cnt[j] >> 1
			cnt[j] %= 2
			j++
		}
		for cnt[j] == 0 {
			cnt[j] = 1
			j++
		}
		ans += j - i
		cnt[j]--
		j = i
		i++
	}
}
```

#### TypeScript

```ts
function minOperations(nums: number[], target: number): number {
    let s = 0;
    const cnt: number[] = Array(32).fill(0);
    for (const x of nums) {
        s += x;
        for (let i = 0; i < 32; ++i) {
            if ((x >> i) & 1) {
                ++cnt[i];
            }
        }
    }
    if (s < target) {
        return -1;
    }
    let [ans, i, j] = [0, 0, 0];
    while (1) {
        while (i < 32 && ((target >> i) & 1) === 0) {
            ++i;
        }
        if (i === 32) {
            return ans;
        }
        while (j < i) {
            cnt[j + 1] += cnt[j] >> 1;
            cnt[j] %= 2;
            ++j;
        }
        while (cnt[j] == 0) {
            cnt[j] = 1;
            j++;
        }
        ans += j - i;
        cnt[j]--;
        j = i;
        i++;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game){#2836}

{{< tabs "2836" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        n, m = len(receiver), k.bit_length()
        f = [[0] * m for _ in range(n)]
        g = [[0] * m for _ in range(n)]
        for i, x in enumerate(receiver):
            f[i][0] = x
            g[i][0] = i
        for j in range(1, m):
            for i in range(n):
                f[i][j] = f[f[i][j - 1]][j - 1]
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1]
        ans = 0
        for i in range(n):
            p, t = i, 0
            for j in range(m):
                if k >> j & 1:
                    t += g[p][j]
                    p = f[p][j]
            ans = max(ans, t + p)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long getMaxFunctionValue(List<Integer> receiver, long k) {
        int n = receiver.size(), m = 64 - Long.numberOfLeadingZeros(k);
        int[][] f = new int[n][m];
        long[][] g = new long[n][m];
        for (int i = 0; i < n; ++i) {
            f[i][0] = receiver.get(i);
            g[i][0] = i;
        }
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            long t = 0;
            for (int j = 0; j < m; ++j) {
                if ((k >> j & 1) == 1) {
                    t += g[p][j];
                    p = f[p][j];
                }
            }
            ans = Math.max(ans, p + t);
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
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size(), m = 64 - __builtin_clzll(k);
        int f[n][m];
        long long g[n][m];
        for (int i = 0; i < n; ++i) {
            f[i][0] = receiver[i];
            g[i][0] = i;
        }
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            long long t = 0;
            for (int j = 0; j < m; ++j) {
                if (k >> j & 1) {
                    t += g[p][j];
                    p = f[p][j];
                }
            }
            ans = max(ans, p + t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaxFunctionValue(receiver []int, k int64) (ans int64) {
	n, m := len(receiver), bits.Len(uint(k))
	f := make([][]int, n)
	g := make([][]int64, n)
	for i := range f {
		f[i] = make([]int, m)
		g[i] = make([]int64, m)
		f[i][0] = receiver[i]
		g[i][0] = int64(i)
	}
	for j := 1; j < m; j++ {
		for i := 0; i < n; i++ {
			f[i][j] = f[f[i][j-1]][j-1]
			g[i][j] = g[i][j-1] + g[f[i][j-1]][j-1]
		}
	}
	for i := 0; i < n; i++ {
		p := i
		t := int64(0)
		for j := 0; j < m; j++ {
			if k>>j&1 == 1 {
				t += g[p][j]
				p = f[p][j]
			}
		}
		ans = max(ans, t+int64(p))
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>receiver</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>总共有&nbsp;<code>n</code>&nbsp;名玩家，玩家 <strong>编号</strong>&nbsp;互不相同，且为&nbsp;<code>[0, n - 1]</code>&nbsp;中的整数。这些玩家玩一个传球游戏，<code>receiver[i]</code>&nbsp;表示编号为 <code>i</code>&nbsp;的玩家会传球给编号为 <code>receiver[i]</code>&nbsp;的玩家。玩家可以传球给自己，也就是说&nbsp;<code>receiver[i]</code>&nbsp;可能等于&nbsp;<code>i</code>&nbsp;。</p>

<p>你需要从 <code>n</code>&nbsp;名玩家中选择一名玩家作为游戏开始时唯一手中有球的玩家，球会被传 <strong>恰好</strong>&nbsp;<code>k</code>&nbsp;次。</p>

<p>如果选择编号为 <code>x</code>&nbsp;的玩家作为开始玩家，定义函数&nbsp;<code>f(x)</code>&nbsp;表示从编号为&nbsp;<code>x</code>&nbsp;的玩家开始，<code>k</code>&nbsp;次传球内所有接触过球玩家的编号之&nbsp;<strong>和</strong>&nbsp;，如果有玩家多次触球，则 <strong>累加多次</strong>&nbsp;。换句话说，&nbsp;<code>f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver<sup>(k)</sup>[x]</code>&nbsp;。</p>

<p>你的任务时选择开始玩家 <code>x</code>&nbsp;，目的是<strong>&nbsp;最大化</strong>&nbsp;<code>f(x)</code>&nbsp;。</p>

<p>请你返回函数的 <strong>最大值</strong>&nbsp;。</p>

<p><strong>注意：</strong><code>receiver</code>&nbsp;可能含有重复元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<th style="padding: 5px; border: 1px solid black;">传递次数</th>
			<th style="padding: 5px; border: 1px solid black;">传球者编号</th>
			<th style="padding: 5px; border: 1px solid black;">接球者编号</th>
			<th style="padding: 5px; border: 1px solid black;">x + 所有接球者编号</th>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">0</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">0</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">5</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">4</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">6</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<pre>
<b>输入：</b>receiver = [2,0,1], k = 4
<b>输出：</b>6
<b>解释：</b>上表展示了从编号为 x = 2 开始的游戏过程。
从表中可知，f(2) 等于 6 。
6 是能得到最大的函数值。
所以输出为 6 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<th style="padding: 5px; border: 1px solid black;">传递次数</th>
			<th style="padding: 5px; border: 1px solid black;">传球者编号</th>
			<th style="padding: 5px; border: 1px solid black;">接球者编号</th>
			<th style="padding: 5px; border: 1px solid black;">x + 所有接球者编号</th>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">&nbsp;</td>
			<td style="padding: 5px; border: 1px solid black;">4</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">4</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">7</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">9</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">10</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<pre>
<b>输入：</b>receiver = [1,1,1,2,3], k = 3
<b>输出：</b>10
<b>解释：</b>上表展示了从编号为 x = 4 开始的游戏过程。
从表中可知，f(4) 等于 10 。
10 是能得到最大的函数值。
所以输出为 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= receiver.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= receiver[i] &lt;= n - 1</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>10</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 倍增

题目要我们寻找从每个玩家 $i$ 开始，传球 $k$ 次内所有接触过球玩家的编号之和的最大值。如果暴力求解，需要从 $i$ 开始向上遍历 $k$ 次，时间复杂度为 $O(k)$，显然会超时。

我们可以使用动态规划，结合倍增的思想来处理。

我们定义 $f[i][j]$ 表示从玩家 $i$ 开始，传球 $2^j$ 次所能到达的玩家编号，定义 $g[i][j]$ 表示从玩家 $i$ 开始，传球 $2^j$ 次所能到达的玩家编号之和（不包括最后一个玩家）。

当 $j=0$ 是，传球次数为 $1$，所以 $f[i][0] = receiver[i]$，而 $g[i][0] = i$。

当 $j \gt 0$ 时，传球次数为 $2^j$，相当于从玩家 $i$ 开始，传球 $2^{j-1}$ 次，再从玩家 $f[i][j-1]$ 开始，传球 $2^{j-1}$ 次，所以 $f[i][j] = f[f[i][j-1]][j-1]$，而 $g[i][j] = g[i][j-1] + g[f[i][j-1]][j-1]$。

接下来，我们可以枚举每个玩家 $i$ 作为开始玩家，然后根据 $k$ 的二进制表示，累计向上查询，最终得到玩家 $i$ 开始，传球 $k$ 次内所有接触过球玩家的编号之和的最大值。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(n \times \log k)$。其中 $n$ 为玩家数。

相似题目：

-   [1483. 树节点的第 K 个祖先](https://github.com/doocs/leetcode/blob/main/solution/1400-1499/1483.Kth%20Ancestor%20of%20a%20Tree%20Node/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        n, m = len(receiver), k.bit_length()
        f = [[0] * m for _ in range(n)]
        g = [[0] * m for _ in range(n)]
        for i, x in enumerate(receiver):
            f[i][0] = x
            g[i][0] = i
        for j in range(1, m):
            for i in range(n):
                f[i][j] = f[f[i][j - 1]][j - 1]
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1]
        ans = 0
        for i in range(n):
            p, t = i, 0
            for j in range(m):
                if k >> j & 1:
                    t += g[p][j]
                    p = f[p][j]
            ans = max(ans, t + p)
        return ans
```

#### Java

```java
class Solution {
    public long getMaxFunctionValue(List<Integer> receiver, long k) {
        int n = receiver.size(), m = 64 - Long.numberOfLeadingZeros(k);
        int[][] f = new int[n][m];
        long[][] g = new long[n][m];
        for (int i = 0; i < n; ++i) {
            f[i][0] = receiver.get(i);
            g[i][0] = i;
        }
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            long t = 0;
            for (int j = 0; j < m; ++j) {
                if ((k >> j & 1) == 1) {
                    t += g[p][j];
                    p = f[p][j];
                }
            }
            ans = Math.max(ans, p + t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size(), m = 64 - __builtin_clzll(k);
        int f[n][m];
        long long g[n][m];
        for (int i = 0; i < n; ++i) {
            f[i][0] = receiver[i];
            g[i][0] = i;
        }
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            long long t = 0;
            for (int j = 0; j < m; ++j) {
                if (k >> j & 1) {
                    t += g[p][j];
                    p = f[p][j];
                }
            }
            ans = max(ans, p + t);
        }
        return ans;
    }
};
```

#### Go

```go
func getMaxFunctionValue(receiver []int, k int64) (ans int64) {
	n, m := len(receiver), bits.Len(uint(k))
	f := make([][]int, n)
	g := make([][]int64, n)
	for i := range f {
		f[i] = make([]int, m)
		g[i] = make([]int64, m)
		f[i][0] = receiver[i]
		g[i][0] = int64(i)
	}
	for j := 1; j < m; j++ {
		for i := 0; i < n; i++ {
			f[i][j] = f[f[i][j-1]][j-1]
			g[i][j] = g[i][j-1] + g[f[i][j-1]][j-1]
		}
	}
	for i := 0; i < n; i++ {
		p := i
		t := int64(0)
		for j := 0; j < m; j++ {
			if k>>j&1 == 1 {
				t += g[p][j]
				p = f[p][j]
			}
		}
		ans = max(ans, t+int64(p))
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2837. 总旅行距离 🔒](https://leetcode.cn/problems/total-traveled-distance){#2837}

{{< tabs "2837" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id, name, IFNULL(SUM(distance), 0) AS 'traveled distance'
FROM
    Users
    LEFT JOIN Rides USING (user_id)
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code><font face="monospace">Users</font></code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| name        | varchar |
+-------------+---------+
user_id 是此表中具有唯一值的列。 
此表的每一行包含用户 id 和姓名。
</pre>

<p>表：<code>Rides</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| ride_id      | int  |
| user_id      | int  | 
| distance     | int  |
+--------------+------+
ride_id 是此表中具有唯一值的列。 
此表中的每一行包含乘车 id、用户 id 和旅行距离。
</pre>

<p>编写一个解决方案，计算每个用户的旅行距离&nbsp;<code>distance</code> 。如果有用户没有任何旅行记录，那么他们的 <code>distance</code>&nbsp;应被视为 <code>0</code> 。输出 <code>user_id</code>,&nbsp;<code>name</code>&nbsp;和总旅行距离&nbsp;<code>traveled distance</code> 。</p>

<p>按 <strong>升序排序</strong> 的 <code>user_id</code> 返回结果表。</p>

<p>结果格式如下示例。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Users table:
+---------+---------+
| user_id | name    |
+---------+---------+
| 17      | Addison |
| 14      | Ethan   |
| 4       | Michael |
| 2       | Avery   |
| 10      | Eleanor |
+---------+---------+
Rides table:
+---------+---------+----------+
| ride_id | user_id | distance |
+---------+---------+----------+
| 72      | 17      | 160      |
| 42      | 14      | 161      |
| 45      | 4       | 59       |
| 32      | 2       | 197      |
| 15      | 4       | 357      |
| 56      | 2       | 196      |
| 10      | 14      | 25       |
+---------+---------+----------+
<b>输出：</b>
+---------+---------+-------------------+
| user_id | name    | traveled distance |
+---------+---------+-------------------+
| 2       | Avery   | 393               |
| 4       | Michael | 416               |
| 10      | Eleanor | 0                 |
| 14      | Ethan   | 186               |
| 17      | Addison | 160               |
+---------+---------+-------------------+
<b>解释：</b>
-  User id 为 2 的用户完成了两次旅行，分别为 197 和 196，总旅行距离为 393。
-  User id 为 4 的用户完成了两次旅行，分别为 59 和 357，总旅行距离为 416。
-  User id 为 14 的用户完成了两次旅行，分别为 161 和 25，总旅行距离为 186。
-  User id 为 16 的用户只完成了一次旅行，距离为 160。
-  User id 为 10 的用户没有完成任何旅行，因此总旅行距离为 0。
按升序排序的 <code>user_id</code> 返回结果表</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组求和

我们可以使用左连接将两张表连接起来，然后使用分组求和的方式计算每个用户的总距离。注意，如果用户没有完成任何骑行，那么他的距离应该被视为 $0$。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT user_id, name, IFNULL(SUM(distance), 0) AS 'traveled distance'
FROM
    Users
    LEFT JOIN Rides USING (user_id)
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2838. 英雄可以获得的最大金币数 🔒](https://leetcode.cn/problems/maximum-coins-heroes-can-collect){#2838}

{{< tabs "2838" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumCoins(
        self, heroes: List[int], monsters: List[int], coins: List[int]
    ) -> List[int]:
        m = len(monsters)
        idx = sorted(range(m), key=lambda i: monsters[i])
        s = list(accumulate((coins[i] for i in idx), initial=0))
        ans = []
        for h in heroes:
            i = bisect_right(idx, h, key=lambda i: monsters[i])
            ans.append(s[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
        int m = monsters.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }

        Arrays.sort(idx, Comparator.comparingInt(j -> monsters[j]));
        long[] s = new long[m + 1];
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + coins[idx[i]];
        }
        int n = heroes.length;
        long[] ans = new long[n];
        for (int k = 0; k < n; ++k) {
            int i = search(monsters, idx, heroes[k]);
            ans[k] = s[i];
        }
        return ans;
    }

    private int search(int[] nums, Integer[] idx, int x) {
        int l = 0, r = idx.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[idx[mid]] > x) {
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
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int m = monsters.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return monsters[i] < monsters[j];
        });
        long long s[m + 1];
        s[0] = 0;
        for (int i = 1; i <= m; ++i) {
            s[i] = s[i - 1] + coins[idx[i - 1]];
        }
        vector<long long> ans;
        auto search = [&](int x) {
            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (monsters[idx[mid]] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        for (int h : heroes) {
            ans.push_back(s[search(h)]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumCoins(heroes []int, monsters []int, coins []int) (ans []int64) {
	m := len(monsters)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return monsters[idx[i]] < monsters[idx[j]] })
	s := make([]int64, m+1)
	for i, j := range idx {
		s[i+1] = s[i] + int64(coins[j])
	}
	for _, h := range heroes {
		i := sort.Search(m, func(i int) bool { return monsters[idx[i]] > h })
		ans = append(ans, s[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumCoins(heroes: number[], monsters: number[], coins: number[]): number[] {
    const m = monsters.length;
    const idx: number[] = Array.from({ length: m }, (_, i) => i);
    idx.sort((i, j) => monsters[i] - monsters[j]);
    const s: number[] = Array(m + 1).fill(0);
    for (let i = 0; i < m; ++i) {
        s[i + 1] = s[i] + coins[idx[i]];
    }
    const search = (x: number): number => {
        let l = 0;
        let r = m;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (monsters[idx[mid]] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    return heroes.map(h => s[search(h)]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一场战斗中，<code>n</code> 位英雄正在试图击败 <code>m</code> 个怪物。你将得到两个下标从 <strong>1</strong> 开始的<strong> 正整数 </strong>数组 <code><font face="monospace">heroes</font></code> 和 <code><font face="monospace">monsters</font></code>，长度分别为 <code>n</code> 和 <code>m</code>。数组 <code><font face="monospace">heroes</font>[i]</code> 代表第 <code>i</code> 位英雄的力量，而 <code><font face="monospace">monsters</font>[i]</code> 代表第 <code>i</code> 个怪物的力量。</p>

<p>如果 <code>monsters[j] &lt;= heroes[i]</code>，则第 <code>i</code> 位英雄可以击败第 <code>j</code> 个怪物。</p>

<p>你还将获得一个下标从 <strong>1</strong> 开始的&nbsp;<strong>正整数</strong> 数组 <code>coins</code>，长度为 <code>m</code> 。数组 <code>coins[i]</code> 表示每位英雄在击败第 <code>i</code> 个怪物后可以获得的金币数。</p>

<p>返回一个长度为 <code>n</code> 的数组 <code>ans</code>，其中 <code>ans[i]</code> 是第 <code>i</code> 位英雄从这场战斗中能收集到的 <strong>最大 </strong>金币数。</p>

<p><strong>注意</strong></p>

<ul>
	<li>击败怪物后，英雄的生命值不会减少。</li>
	<li>多位英雄可以击败同一个怪物，但每个怪物只能被同一位英雄击败一次。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>heroes = [1,4,2], monsters = [1,1,5,2,3], coins = [2,3,4,5,6]
<strong>输出：</strong>[5,16,10]
<strong>解释：</strong>对于每位英雄，我们列出了所有他可以击败的怪物的下标：
第 1 位英雄：[1,2]，因为这位英雄的力量为 1，且 monsters[1], monsters[2] &lt;= 1。因此这位英雄收集的金币为 coins[1] + coins[2] = 5 金币。
第 2 位英雄：[1,2,4,5]，因为这位英雄的力量为 4，且 monsters[1], monsters[2], monsters[4], monsters[5] &lt;= 4。因此这位英雄收集的金币为 coins[1] + coins[2] + coins[4] + coins[5] = 16 金币。
第 3 位英雄：[1,2,4]，因为这位英雄的力量为 2，且 monsters[1], monsters[2], monsters[4] &lt;= 2。因此这位英雄收集的金币为 coins[1] + coins[2] + coins[4] = 10 金币。
因此答案为 [5,16,10]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>heroes = [5], monsters = [2,3,1,2], coins = [10,6,5,2]
<strong>输出：</strong>[23]
<strong>解释：</strong>这位英雄可以击败所有怪物，因为 monsters[i] &lt;= 5。所以他收集了所有的金币：coins[1] + coins[2] + coins[3] + coins[4] = 23，因此答案为 [23]。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>heroes = [4,4], monsters = [5,7,8], coins = [1,1,1]
<strong>输出：</strong>[0,0]
<strong>解释：</strong>在这个例子中，没有英雄可以击败怪物。因此答案为 [0,0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == heroes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m == monsters.length &lt;= 10<sup>5</sup></code></li>
	<li><code>coins.length == m</code></li>
	<li><code>1 &lt;= heroes[i], monsters[i], coins[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找

我们可以将怪物和金币按照怪物的战斗力从小到大排序，然后使用前缀和计算每个英雄打败前 $i$ 个怪物可以获得的金币总数。

接下来，对于每个英雄，我们可以使用二分查找找到他可以打败的最大的怪物，然后使用前缀和计算他可以获得的金币总数即可。

时间复杂度 $O((m + n) \times \log n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是怪物和英雄的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCoins(
        self, heroes: List[int], monsters: List[int], coins: List[int]
    ) -> List[int]:
        m = len(monsters)
        idx = sorted(range(m), key=lambda i: monsters[i])
        s = list(accumulate((coins[i] for i in idx), initial=0))
        ans = []
        for h in heroes:
            i = bisect_right(idx, h, key=lambda i: monsters[i])
            ans.append(s[i])
        return ans
```

#### Java

```java
class Solution {
    public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
        int m = monsters.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }

        Arrays.sort(idx, Comparator.comparingInt(j -> monsters[j]));
        long[] s = new long[m + 1];
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + coins[idx[i]];
        }
        int n = heroes.length;
        long[] ans = new long[n];
        for (int k = 0; k < n; ++k) {
            int i = search(monsters, idx, heroes[k]);
            ans[k] = s[i];
        }
        return ans;
    }

    private int search(int[] nums, Integer[] idx, int x) {
        int l = 0, r = idx.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[idx[mid]] > x) {
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
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int m = monsters.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return monsters[i] < monsters[j];
        });
        long long s[m + 1];
        s[0] = 0;
        for (int i = 1; i <= m; ++i) {
            s[i] = s[i - 1] + coins[idx[i - 1]];
        }
        vector<long long> ans;
        auto search = [&](int x) {
            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (monsters[idx[mid]] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        for (int h : heroes) {
            ans.push_back(s[search(h)]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumCoins(heroes []int, monsters []int, coins []int) (ans []int64) {
	m := len(monsters)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return monsters[idx[i]] < monsters[idx[j]] })
	s := make([]int64, m+1)
	for i, j := range idx {
		s[i+1] = s[i] + int64(coins[j])
	}
	for _, h := range heroes {
		i := sort.Search(m, func(i int) bool { return monsters[idx[i]] > h })
		ans = append(ans, s[i])
	}
	return
}
```

#### TypeScript

```ts
function maximumCoins(heroes: number[], monsters: number[], coins: number[]): number[] {
    const m = monsters.length;
    const idx: number[] = Array.from({ length: m }, (_, i) => i);
    idx.sort((i, j) => monsters[i] - monsters[j]);
    const s: number[] = Array(m + 1).fill(0);
    for (let i = 0; i < m; ++i) {
        s[i + 1] = s[i] + coins[idx[i]];
    }
    const search = (x: number): number => {
        let l = 0;
        let r = m;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (monsters[idx[mid]] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    return heroes.map(h => s[search(h)]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2839. 判断通过操作能否让字符串相等 I](https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i){#2839}

{{< tabs "2839" >}}

{{% tab "python" %}}
```python
class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return sorted(s1[::2]) == sorted(s2[::2]) and sorted(s1[1::2]) == sorted(
            s2[1::2]
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canBeEqual(String s1, String s2) {
        int[][] cnt = new int[2][26];
        for (int i = 0; i < s1.length(); ++i) {
            ++cnt[i & 1][s1.charAt(i) - 'a'];
            --cnt[i & 1][s2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] != 0 || cnt[1][i] != 0) {
                return false;
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
    bool canBeEqual(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canBeEqual(s1 string, s2 string) bool {
	cnt := [2][26]int{}
	for i := 0; i < len(s1); i++ {
		cnt[i&1][s1[i]-'a']++
		cnt[i&1][s2[i]-'a']--
	}
	for i := 0; i < 26; i++ {
		if cnt[0][i] != 0 || cnt[1][i] != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canBeEqual(s1: string, s2: string): boolean {
    const cnt: number[][] = Array.from({ length: 2 }, () => Array.from({ length: 26 }, () => 0));
    for (let i = 0; i < s1.length; ++i) {
        ++cnt[i & 1][s1.charCodeAt(i) - 97];
        --cnt[i & 1][s2.charCodeAt(i) - 97];
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[0][i] || cnt[1][i]) {
            return false;
        }
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

<p>给你两个字符串&nbsp;<code>s1</code> 和&nbsp;<code>s2</code>&nbsp;，两个字符串的长度都为&nbsp;<code>4</code>&nbsp;，且只包含 <strong>小写</strong> 英文字母。</p>

<p>你可以对两个字符串中的 <strong>任意一个</strong>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;且满足&nbsp;<code>j - i = 2</code>&nbsp;，然后 <strong>交换</strong> 这个字符串中两个下标对应的字符。</li>
</ul>

<p>如果你可以让字符串<em>&nbsp;</em><code>s1</code><em> </em>和<em>&nbsp;</em><code>s2</code>&nbsp;相等，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "abcd", s2 = "cdab"
<b>输出：</b>true
<strong>解释：</strong> 我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbad" 。
- 选择下标 i = 1 ，j = 3 ，得到字符串 s1 = "cdab" = s2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "abcd", s2 = "dacb"
<b>输出：</b>false
<b>解释：</b>无法让两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s1.length == s2.length == 4</code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们观察题目中的操作，可以发现，如果字符串的两个下标 $i$ 和 $j$ 的奇偶性相同，那么它们可以通过交换改变顺序。

因此，我们可以统计两个字符串中奇数下标的字符的出现次数，以及偶数下标的字符的出现次数，如果两个字符串的统计结果相同，那么我们就可以通过操作使得两个字符串相等。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串的长度，而 $\Sigma$ 是字符集。

相似题目：

-   [2840. 判断通过操作能否让字符串相等 II](https://github.com/doocs/leetcode/blob/main/solution/2800-2899/2840.Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return sorted(s1[::2]) == sorted(s2[::2]) and sorted(s1[1::2]) == sorted(
            s2[1::2]
        )
```

#### Java

```java
class Solution {
    public boolean canBeEqual(String s1, String s2) {
        int[][] cnt = new int[2][26];
        for (int i = 0; i < s1.length(); ++i) {
            ++cnt[i & 1][s1.charAt(i) - 'a'];
            --cnt[i & 1][s2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] != 0 || cnt[1][i] != 0) {
                return false;
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
    bool canBeEqual(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canBeEqual(s1 string, s2 string) bool {
	cnt := [2][26]int{}
	for i := 0; i < len(s1); i++ {
		cnt[i&1][s1[i]-'a']++
		cnt[i&1][s2[i]-'a']--
	}
	for i := 0; i < 26; i++ {
		if cnt[0][i] != 0 || cnt[1][i] != 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canBeEqual(s1: string, s2: string): boolean {
    const cnt: number[][] = Array.from({ length: 2 }, () => Array.from({ length: 26 }, () => 0));
    for (let i = 0; i < s1.length; ++i) {
        ++cnt[i & 1][s1.charCodeAt(i) - 97];
        --cnt[i & 1][s2.charCodeAt(i) - 97];
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[0][i] || cnt[1][i]) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
